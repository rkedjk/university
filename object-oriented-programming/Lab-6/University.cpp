#include "University.h"

int University::maxArrayIndex(int length, int *arr) // Max Array index
{
	if (length <= 0)
		throw Exception("Invalid array length value.");
	int max = arr[0];
	int max_i = 0;
	for (int i = 0; i < length; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
			max_i = i;
		}
	}
	return max_i;
}

int University::minArrayIndex(int length, int *arr) // Min array index
{
	if (length <= 0)
		throw Exception("Invalid array length value.");
	int min = arr[0];
	int min_i = 0;
	for (int i = 0; i < length; i++)
	{
		if (arr[i] < min)
		{
			min = arr[i];
			min_i = i;
		}
	}
	return min_i;
}

int University::random(int min, int max) // Random generation
{
	if (max < min)
	{
		swap(min, max);
	}
	return min + rand() % (1 + max - min);
}

void University::PeremeshivanieMassiva(int m[], int size)
{
	if (size <= 0)
		throw Exception("Invalid array size value.");
	for (int i = 0; i < size; ++i)
		std::swap(m[i], m[std::rand() % size]);
}

University::University()
{
	facultyCount = 0;
}

University::~University()
{
	fac.clear();
}

void University::addHumans(const char *fio, int yearBirth, H_Types type)
{
	if (type == H_Types::STUD)
		fac.push_back(new Student(fio, yearBirth));
	else if (type == H_Types::TEACH)
		fac.push_back(new Teacher(fio, yearBirth));
	else if (type == H_Types::H_TEACH)
		fac.push_back(new HeadTeacher(fio, yearBirth));
	else if (type == H_Types::RESEARCH)
		fac.push_back(new Research(fio, yearBirth));
	facultyCount += 1;
}

void University::addHumans(const char *fio, int yearBirth, int type)
{
	if (type == 1)
		fac.push_back(new Student(fio, yearBirth));
	else if (type == 2)
		fac.push_back(new Teacher(fio, yearBirth));
	else if (type == 3)
		fac.push_back(new HeadTeacher(fio, yearBirth));
	else if (type == 4)
		fac.push_back(new Research(fio, yearBirth));
	facultyCount += 1;
}

void University::addRandomHumans(int N)
{
	if (N <= 0)
		throw Exception("Invalid value!");
	int sz = fac.size() + N;
	string names[10] = {"Dmitry", "Andrey", "Ilya", "Anton", "Gleb", "Daniel", "Yaroslav", "Maxim", "Gregory", "Vladimir"};
	string surnames[10] = {"Kalashnikov", "Samoilov", "Kulikov", "Semenov", "Zuev", "Serov", "Shmelev", "Kuleshov", "Dubov", "Vinokurov"};
	int k1 = 0, k2 = 0, k3 = 0, k4 = 0;
	int *id_type1 = new int[sz];
	int *id_type2 = new int[sz];
	int *id_type3 = new int[sz];
	int *id_type4 = new int[sz];
	bool fl = fac.empty();
	if (not fl)
	{
		it = fac.begin();
		for (it = fac.begin(); it != fac.end(); ++it)
		{
			H_Types tp = (*it)->getTypeHuman();
			switch (tp)
			{
			case H_Types::STUD:
			{
				id_type1[k1++] = (*it)->getId();
				break;
			}
			case H_Types::TEACH:
			{
				id_type2[k2++] = (*it)->getId();
				break;
			}
			case H_Types::H_TEACH:
			{
				id_type3[k3++] = (*it)->getId();
				break;
			}
			case H_Types::RESEARCH:
			{
				id_type4[k4++] = (*it)->getId();
				break;
			}
			}
		}
	}
	int nk1 = k1, nk2 = k2, nk3 = k3, nk4 = k4;

	for (int i = 0; i < N; ++i)
	{
		H_Types tkp = static_cast<H_Types>(random(1, 4) - 1);
		switch (tkp)
		{
		case H_Types::STUD:
		{
			fac.push_back(new Student((names[rand() % 10] + " " + surnames[rand() % 10]).c_str(), random(1999, 2005)));
			id_type1[k1++] = (fac.back())->getId();
			break;
		}
		case H_Types::TEACH:
		{
			fac.push_back(new Teacher((names[rand() % 10] + " " + surnames[rand() % 10]).c_str(), random(1950, 1995)));
			id_type2[k2++] = (fac.back())->getId();
			break;
		}
		case H_Types::H_TEACH:
		{
			fac.push_back(new HeadTeacher((names[rand() % 10] + " " + surnames[rand() % 10]).c_str(), random(1950, 1990)));
			id_type3[k3++] = (fac.back())->getId();
			break;
		}
		case H_Types::RESEARCH:
		{
			fac.push_back(new Research((names[rand() % 10] + " " + surnames[rand() % 10]).c_str(), random(1980, 1997)));
			id_type4[k4++] = (fac.back())->getId();
			break;
		}
		}
		facultyCount += 1;
	}

	for (int j = nk1; j < k1; ++j)
	{
		int id = id_type1[j];
		int k_subj = random(1, MAX_SUBJECTS);
		try
		{
			for (int k_s = 0; k_s < k_subj; ++k_s)
				this->getHumanID(id)->setValue(random(0, MAX_SUBJECTS - 1), random(random(2, 4), 5));
		}
		catch (Exception &e)
		{
			cout << e.getInfo() << endl;
		}
	}

	for (int j = nk2; j < k2; ++j)
	{
		int id = id_type2[j];
		int k_subj = random(1, MAX_SUBJECTS);
		try
		{
			for (int k_s = 0; k_s < k_subj; ++k_s)
				this->getHumanID(id)->setValue(random(0, MAX_SUBJECTS - 1), random(80, 144) / k_subj);
		}
		catch (Exception &e)
		{
			cout << e.getInfo() << endl;
		}
	}

	for (int j = nk3; j < k3; ++j)
	{
		int id = id_type3[j];
		int k_subj = random(1, MAX_SUBJECTS);
		try
		{
			for (int k_s = 0; k_s < k_subj; ++k_s)
				this->getHumanID(id)->setValue(random(0, MAX_SUBJECTS - 1), random(80, 144) / k_subj);
		}
		catch (Exception &e)
		{
			cout << e.getInfo() << endl;
		}
		if (k2 > 0)
		{
			int k_zams = random(1, k2);
			try
			{
				PeremeshivanieMassiva(id_type2, k2);
			}
			catch (Exception &e)
			{
				cout << e.getInfo() << endl;
			}
			try
			{
				for (int k_z = 0; k_z < k_zams; ++k_z)
					this->getHumanID(id)->addMinien(this->getHumanID(id_type2[k_z]));
			}
			catch (Exception &e)
			{
				cout << e.getInfo() << endl;
			}
		}
	}

	for (int j = nk4; j < k4; ++j)
	{
		int id = id_type4[j];
		int k_subj = random(1, MAX_SUBJECTS);
		try
		{
			for (int k_s = 0; k_s < k_subj; ++k_s)
				this->getHumanID(id)->setValue(random(0, MAX_SUBJECTS - 1), random(80, 144) / k_subj);
		}
		catch (Exception &e)
		{
			cout << e.getInfo() << endl;
		}
		if (k1 > 0)
		{
			int k_studs = random(1, k1);
			try
			{
				PeremeshivanieMassiva(id_type1, k1);
			}
			catch (Exception &e)
			{
				cout << e.getInfo() << endl;
			}
			try
			{
				for (int k_s = 0; k_s < k_studs; ++k_s)
					this->getHumanID(id)->addMinien(this->getHumanID(id_type1[k_s]));
			}
			catch (Exception &e)
			{
				cout << e.getInfo() << endl;
			}
		}
	}
	delete[] id_type1;
	delete[] id_type2;
	delete[] id_type3;
	delete[] id_type4;
}

void University::removeHumanID(int id)
{
	it = fac.begin();

	for (it = fac.begin(); it != fac.end(); ++it)
	{
		if (id == (*it)->getId())
		{
			delete (*it);
			fac.erase(it);
			--facultyCount;
			return;
		}
	}

	cout << "Failed to delete find an entity with such ID..." << endl;
}

void University::removeHumans()
{
	it = fac.begin();
	for (it = fac.begin(); it != fac.end(); ++it)
	{
		delete (*it);
		fac.erase(it);
		--facultyCount;
		--it;
	}
	return;
}

float University::allMoney()
{
	if (fac.empty())
		throw Exception("There are no entities. Nobody was paid.");
	it = fac.begin();
	sumMoney = 0;
	for (it = fac.begin(); it != fac.end(); ++it)
		sumMoney += (*it)->getFullPay();
	return sumMoney;
}

void University::avgMoney()
{
	if (fac.empty())
		throw Exception("There are no entities. Nobody was paid.");
	float sM1 = 0, sM2 = 0, sM3 = 0, sM4 = 0;
	int k1 = 0, k2 = 0, k3 = 0, k4 = 0;

	it = fac.begin();
	for (it = fac.begin(); it != fac.end(); ++it)
	{
		H_Types tp = (*it)->getTypeHuman();
		switch (tp)
		{
		case H_Types::STUD:
		{
			sM1 += (*it)->getFullPay();
			k1++;
			break;
		}
		case H_Types::TEACH:
		{
			sM2 += (*it)->getFullPay();
			k2++;
			break;
		}
		case H_Types::H_TEACH:
		{
			sM3 += (*it)->getFullPay();
			k3++;
			break;
		}
		case H_Types::RESEARCH:
		{
			sM4 += (*it)->getFullPay();
			k4++;
			break;
		}
		}
	}
	if (k1 > 0)
	{
		cout << "Average PO for students: " << sM1 / k1 << endl;
	}
	else
	{
		cout << "There are no students!" << endl;
	}
	if (k2 > 0)
	{
		cout << "Average PO for teachers: " << sM2 / k2 << endl;
	}
	else
	{
		cout << "No teachers!" << endl;
	}
	if (k3 > 0)
	{
		cout << "Average PO to the head: " << sM3 / k3 << endl;
	}
	else
	{
		cout << "There are no managers!" << endl;
	}
	if (k4 > 0)
	{
		cout << "Average PO for researchers: " << sM4 / k4 << endl;
	}
	else
	{
		cout << "There are no scientific staff!" << endl;
	}
}

Human *University::getHumanID(int id)
{
	it = fac.begin();
	for (it = fac.begin(); it != fac.end(); ++it)
	{
		if (id == (*it)->getId())
		{
			return *it;
		}
	}
	cout << "Failed to delete find an entity with such ID..." << endl;
}

bool University::checkHumanID(int id)
{
	it = fac.begin();
	for (it = fac.begin(); it != fac.end(); ++it)
	{
		if (id == (*it)->getId())
		{
			return true;
		}
	}
	return false;
}

Human *University::getHumans(int i)
{
	it = fac.begin();
	return *(it + i);
}

int University::getFacultyCount() { return fac.size(); }

void University::printAboutHuman(int k)
{
	string tName;
	cout << "The university consists of " << fac.size() << " personalities:" << endl;
	it = fac.begin();
	for (it = fac.begin(); it != fac.end(); ++it)
	{
		if ((*it)->getTypeHuman() == H_Types::STUD)
			tName = " Student.";
		else if ((*it)->getTypeHuman() == H_Types::TEACH)
			tName = "Teacher.";
		else if ((*it)->getTypeHuman() == H_Types::H_TEACH)
			tName = "Head.";
		else if ((*it)->getTypeHuman() == H_Types::RESEARCH)
			tName = "Researcher.";
		cout << (*it)->getId() << ") " << (*it)->getFIO() << " " << (*it)->getAge() << " years." << tName << endl;
		if (k == 1)
		{
			(*it)->printAbout();
			try
			{
				(*it)->printAboutMiniens();
			}
			catch (Exception &e)
			{
				cout << e.getInfo() << endl;
			}
		}
	}

	cout << endl;
}

void University::CompAge()
{
	int sz = fac.size();
	int *year_type1 = new int[sz];
	int *year_type2 = new int[sz];
	int *year_type3 = new int[sz];
	int *year_type4 = new int[sz];
	int *id_type1 = new int[sz];
	int *id_type2 = new int[sz];
	int *id_type3 = new int[sz];
	int *id_type4 = new int[sz];
	int k1 = 0, k2 = 0, k3 = 0, k4 = 0;

	it = fac.begin();
	for (it = fac.begin(); it != fac.end(); ++it)
	{
		H_Types tp = (*it)->getTypeHuman();
		switch (tp)
		{
		case H_Types::STUD:
		{
			year_type1[k1] = (*it)->getAge();
			id_type1[k1++] = (*it)->getId();
			break;
		}
		case H_Types::TEACH:
		{
			year_type2[k2] = (*it)->getAge();
			id_type2[k2++] = (*it)->getId();
			break;
		}
		case H_Types::H_TEACH:
		{
			year_type3[k3] = (*it)->getAge();
			id_type3[k3++] = (*it)->getId();
			break;
		}
		case H_Types::RESEARCH:
		{
			year_type4[k4] = (*it)->getAge();
			id_type4[k4++] = (*it)->getId();
			break;
		}
		}
	}

	if (k1 > 0)
	{
		try
		{
			cout << endl
				 << "Youngest student:" << endl;
		}
		catch (Exception &e)
		{
			cout << e.getInfo() << endl;
		}
		this->getHumanID(id_type1[minArrayIndex(k1, year_type1)])->printAbout();
		try
		{
			cout << endl
				 << "The oldest student:" << endl;
			this->getHumanID(id_type1[maxArrayIndex(k1, year_type1)])->printAbout();
		}
		catch (Exception &e)
		{
			cout << e.getInfo() << endl;
		}
	}
	else
	{
		cout << "No students!" << endl;
	}
	if (k2 > 0)
	{
		try
		{
			cout << endl
				 << "The youngest teacher:" << endl;
			this->getHumanID(id_type2[minArrayIndex(k2, year_type2)])->printAbout();
		}
		catch (Exception &e)
		{
			cout << e.getInfo() << endl;
		}
		try
		{
			cout << endl
				 << "The most senior teacher:" << endl;
			this->getHumanID(id_type2[maxArrayIndex(k2, year_type2)])->printAbout();
		}
		catch (Exception &e)
		{
			cout << e.getInfo() << endl;
		}
	}
	else
	{
		cout << "No teachers!" << endl;
	}
	if (k3 > 0)
	{
		try
		{
			cout << endl
				 << "The youngest head:" << endl;
			this->getHumanID(id_type3[minArrayIndex(k3, year_type3)])->printAbout();
		}
		catch (Exception &e)
		{
			cout << e.getInfo() << endl;
		}
		try
		{
			cout << endl
				 << "The most senior manager:" << endl;
			this->getHumanID(id_type3[maxArrayIndex(k3, year_type3)])->printAbout();
		}
		catch (Exception &e)
		{
			cout << e.getInfo() << endl;
		}
	}
	else
	{
		cout << "No supervisors!" << endl;
	}
	if (k4 > 0)
	{
		try
		{
			cout << endl
				 << "The youngest researcher:" << endl;
			this->getHumanID(id_type4[minArrayIndex(k4, year_type4)])->printAbout();
		}
		catch (Exception &e)
		{
			cout << e.getInfo() << endl;
		}
		try
		{
			cout << endl
				 << "The most senior researcher:" << endl;
			this->getHumanID(id_type4[maxArrayIndex(k4, year_type4)])->printAbout();
		}
		catch (Exception &e)
		{
			cout << e.getInfo() << endl;
		}
	}
	else
	{
		cout << "No research staff!" << endl;
	}
	delete[] id_type1;
	delete[] id_type2;
	delete[] id_type3;
	delete[] id_type4;
	delete[] year_type1;
	delete[] year_type2;
	delete[] year_type3;
	delete[] year_type4;
}
