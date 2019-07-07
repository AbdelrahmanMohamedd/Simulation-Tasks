#include <iostream>
#include <random>
#include <ctime>

using namespace std;
int generate(const int&, const int&, const int&);
int generate_seeded(const int&, const int&);
int generate_engine_out(const int&, const int&, default_random_engine&);
int generate_inside_static(const int&, const int&);

int main()
{
	//Normal Case.
	default_random_engine generator1;
	uniform_int_distribution<int> dist1(1, 10);
	cout << "Normal Distrubtion." << endl;
	for (int i = 0; i < 10; i++)
	{
		int random_number = dist1(generator1);
		cout << random_number << endl;
	}
	cout << endl;
	//Normal Seeded Case.
	default_random_engine generator2;
	generator2.seed(time(0));
	uniform_int_distribution<int> dist2(1, 10);
	cout << "Seeded With Time." << endl;
	for (int i = 0; i < 10; i++)
	{
		int random_number = dist2(generator2);
		cout << random_number << endl;
	}
	cout << endl;
	//Generator Inside Case;
	cout << "Generator Inside Case." << endl;
	for (int i = 0; i < 10; i++)
	{
		int random_number = generate(1, 10, i);
		cout << random_number << endl;
	}
	cout << endl;
	cout << "Generator Inside Seeded Case." << endl;
	for (int i = 0; i < 10; i++)
	{
		int random_number = generate_seeded(1, 10);
		cout << random_number << endl;
	}
	cout << endl;
	cout << "Generator Outside Case." << endl;
	default_random_engine generator3;
	generator3.seed(time(0));
	for (int i = 0; i < 10; i++)
	{
		int random_number = generate_engine_out(1, 10, generator3);
		cout << random_number << endl;
	}
	cout << endl;
	cout << "Generator Inside Static." << endl;
	for(int i = 0; i < 10; i++)
    {
        int random_number = generate_inside_static(1, 10);
        cout << random_number << endl;
    }
	system("Pause");
	return 0;
}

int generate(const int& min, const int& max, const int& index)
{
	default_random_engine generator;
	//generator.discard(index);
	uniform_int_distribution<int> dist(min, max);
	return dist(generator);
}

int generate_seeded(const int& min, const int& max)
{
	default_random_engine generator;
	generator.seed(time(0));
	uniform_int_distribution<int> dist(min, max);
	return dist(generator);
}

int generate_engine_out(const int& min, const int& max, default_random_engine& generator)
{
	uniform_int_distribution<int> dist(min, max);
	return dist(generator);
}
int generate_inside_static(const int& min, const int& max)
{
    static default_random_engine generator(time(0));
    uniform_int_distribution<int> dist(min, max);
    return dist(generator);
}
