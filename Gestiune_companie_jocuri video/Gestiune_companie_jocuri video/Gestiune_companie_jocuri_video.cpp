#include <iostream>
#include <cstring> 
#include <vector>

using namespace std;

class VideoGame 
{
private:
    char* title;
    string genre;
    string platform;
    float price;

public:
    // Constructors
    VideoGame() : title(nullptr), genre("Unknown"), platform("Unknown"), price(0) 
    {
    
    }

    VideoGame(const char* title, string genre, string platform, float price)
        : title(nullptr), genre(genre), platform(platform), price(price) 
    {
        setTitle(title);
    }

    VideoGame(const VideoGame& vg) : VideoGame(vg.title, vg.genre, vg.platform, vg.price) 
    {

    }

    // Destructor
    ~VideoGame() 
    {
        delete[] title;
    }

    // Assignment operator
    VideoGame& operator=(const VideoGame& vg) 
    {
        if (this != &vg) 
        {
            delete[] title;
            title = nullptr;
            genre = vg.genre;
            platform = vg.platform;
            price = vg.price;
            setTitle(vg.title);
        }
        return *this;
    }

    //== operator
    bool operator==(const VideoGame& vg) const {

        bool titleResult = (strcmp(title, vg.title) == 0);
        bool genreResult = (genre == vg.genre);
        bool platformResult = (platform == vg.platform);
        bool priceResult = (price == vg.price);

        return titleResult && genreResult && platformResult && priceResult;
    }

    // Getters
    const char* getTitle() const 
    {
        return title;
    }

    string getGenre() const 
    {
        return genre;
    }

    string getPlatform() const 
    {
        return platform;
    }

    float getPrice() const 
    {
        return price;
    }

    // Setters
    void setTitle(const char* newTitle) 
    {
        delete[] title;
        if (newTitle != nullptr) 
        {
            title = new char[strlen(newTitle) + 1];
            strcpy_s(title, strlen(newTitle) + 1, newTitle);
        }
        else 
        {
            title = nullptr;
        }
    }

    // Input and Output operators
    friend istream& operator>>(istream& is, VideoGame& vg) 
    {
        delete[] vg.title;
        
        cout << "Enter title: ";

        is.ignore();
        char aux[100];
        
        is.getline(aux, sizeof(aux));
        vg.setTitle(aux);

        cout << "Enter genre: ";

        is >> vg.genre;

        cout << "Enter platform: ";

        is >> vg.platform;

        cout << "Enter price: ";

        is >> vg.price;

        /*is.ignore(numeric_limits<streamsize>::max(), '\n');*/

        return is;
    }

    friend ostream& operator<<(ostream& os, const VideoGame& vg) 
    {
        os << "Title: " << vg.title << endl;
        os << "Genre: " << vg.genre << endl;
        os << "Platform: " << vg.platform << endl;
        os << "Price: " << vg.price << endl;

        return os;
    }
};

class AdventureGame : public VideoGame 
{
private:
    char* difficultyLevel;
    int missionCount;

public:
    // Constructors
    AdventureGame() : VideoGame(nullptr, "Unknown", "Unknown", 0), difficultyLevel(nullptr), missionCount(0) 
    {
    
    }

    AdventureGame(const char* difficultyLevel, int missionCount,
        const char* title, string genre, string platform, float price)
        : VideoGame(title, genre, platform, price), difficultyLevel(nullptr), missionCount(missionCount) 
    {
        setDifficultyLevel(difficultyLevel);
    }

    AdventureGame(const AdventureGame& ag) : VideoGame(ag), difficultyLevel(nullptr), missionCount(ag.missionCount) 
    {
        setDifficultyLevel(ag.difficultyLevel);
    }

    // Destructor
    ~AdventureGame() 
    {
        delete[] difficultyLevel;
    }

    // Assignment operator
    AdventureGame& operator=(const AdventureGame& ag) 
    {
        if (this != &ag) 
        {
            VideoGame::operator=(ag);
            delete[] difficultyLevel;
            difficultyLevel = nullptr;
            missionCount = ag.missionCount;
            setDifficultyLevel(ag.difficultyLevel);
        }
        return *this;
    }

    // Getters
    const char* getDifficultyLevel() const 
    {
        return difficultyLevel;
    }

    int getMissionCount() const 
    {
        return missionCount;
    }

    // Setters
    void setDifficultyLevel(const char* newDifficultyLevel) 
    {
        delete[] difficultyLevel;
        if (newDifficultyLevel != nullptr) 
        {
            difficultyLevel = new char[strlen(newDifficultyLevel) + 1];
            strcpy_s(difficultyLevel, strlen(newDifficultyLevel) + 1, newDifficultyLevel);
        }
        else 
        {
            difficultyLevel = nullptr;
        }
    }

    void setMissionCount(int newMissionCount) 
    {
        missionCount = newMissionCount;
    }

    // Input and Output operators
    friend istream& operator>>(istream& is, AdventureGame& ag)
    {
        is >> static_cast<VideoGame&>(ag);

        cout << "Enter difficulty level: ";

        char aux[100];

        is.ignore();
        is.getline(aux, sizeof(aux));
        ag.setDifficultyLevel(aux);

        cout << "Enter mission count: ";

        is >> ag.missionCount;

        return is;
    }

    friend ostream& operator<<(ostream& os, const AdventureGame& ag) 
    {
        os << static_cast<const VideoGame&>(ag);
        os << "Difficulty level: " << ag.difficultyLevel << endl;
        os << "Mission count: " << ag.missionCount << endl;
        return os;
    }
};

class StrategyGame : public VideoGame 
{
private:
    char* strategyType;
    int playerCount;

public:
    // Constructors
    StrategyGame() : VideoGame(nullptr, "Unknown", "Unknown", 0), strategyType(nullptr), playerCount(0) 
    {

    }

    StrategyGame(const char* strategyType, int playerCount,
        const char* title, string genre, string platform, float price)
        : VideoGame(title, genre, platform, price), strategyType(nullptr), playerCount(playerCount) 
    {
        setStrategyType(strategyType);
    }

    StrategyGame(const StrategyGame& sg) : VideoGame(sg), strategyType(nullptr), playerCount(sg.playerCount) 
    {
        setStrategyType(sg.strategyType);
    }

    // Assignment operator
    StrategyGame& operator=(const StrategyGame& sg) 
    {
        if (this != &sg) 
        {
            VideoGame::operator=(sg);
            delete[] strategyType;
            strategyType = nullptr;
            playerCount = sg.playerCount;
            setStrategyType(sg.strategyType);
        }
        return *this;
    }

    // Getters
    const char* getStrategyType() const 
    {
        return strategyType;
    }

    int getPlayerCount() const 
    {
        return playerCount;
    }

    // Setters
    void setStrategyType(const char* newStrategyType) 
    {
        delete[] strategyType;
        if (newStrategyType != nullptr) 
        {
            strategyType = new char[strlen(newStrategyType) + 1];
            strcpy_s(strategyType, strlen(newStrategyType) + 1, newStrategyType);
        }
        else 
        {
            strategyType = nullptr;
        }
    }

    void setPlayerCount(int newPlayerCount) 
    {
        playerCount = newPlayerCount;
    }

    // Input and Output operators
    friend istream& operator>>(istream& is, StrategyGame& sg) 
    {
        is >> static_cast<VideoGame&>(sg);
        cout << "Enter strategy type: ";

        char aux[100];

        is.ignore();
        is.getline(aux, sizeof(aux));
        sg.setStrategyType(aux);

        cout << "Enter player count: ";

        is >> sg.playerCount;

        return is;
    }

    friend ostream& operator<<(ostream& os, const StrategyGame& sg) 
    {
        os << static_cast<const VideoGame&>(sg);
        os << "Strategy type: " << sg.strategyType << endl;
        os << "Player count: " << sg.playerCount << endl;
        return os;
    }

    // Destructor
    ~StrategyGame()
    {
        delete[] strategyType;
    }
};

class VideoGameCompany 
{
private:
    vector<VideoGame> availableGames;
    int employeeCount;
    float annualRevenue;

public:
    // Constructors
    VideoGameCompany() : employeeCount(0), annualRevenue(0.0)
    {

    }

    VideoGameCompany(const vector<VideoGame>& games, int employees, float revenue)
        : availableGames(games), employeeCount(employees), annualRevenue(revenue)
    {

    }

    VideoGameCompany(const VideoGameCompany& vgc)
        : availableGames(vgc.availableGames), employeeCount(vgc.employeeCount), annualRevenue(vgc.annualRevenue)
    {

    }

    // Assignment operator
    VideoGameCompany& operator=(const VideoGameCompany& vgc)
    {
        if (this != &vgc)
        {
            availableGames = vgc.availableGames;
            employeeCount = vgc.employeeCount;
            annualRevenue = vgc.annualRevenue;
        }
        return *this;
    }

    // Getters
    const vector<VideoGame>& getAvailableGames() const
    {
        return availableGames;
    }

    int getEmployeeCount() const
    {
        return employeeCount;
    }

    float getAnnualRevenue() const
    {
        return annualRevenue;
    }

    // Setters
    void setAvailableGames(const vector<VideoGame>& newGames)
    {
        availableGames = newGames;
    }

    void setEmployeeCount(int employees)
    {
        employeeCount = employees;
    }

    void setAnnualRevenue(float newRevenue)
    {
        annualRevenue = newRevenue;
    }

    // += operator
    VideoGameCompany& operator+=(const VideoGame& gameToAdd)
    {
        availableGames.push_back(gameToAdd);
        return *this;
    }

    // -=
    VideoGameCompany& operator-=(const VideoGame& gameToRemove)
    {
        auto it = find(availableGames.begin(), availableGames.end(), gameToRemove);

        if (it != availableGames.end()) {
            availableGames.erase(it);
        }

        return *this;
    }

    // [] operator 
    const VideoGame& operator[](int index) const {
        if (index < availableGames.size()) {
            return availableGames[index];
        }
        else {
            throw out_of_range("Index out of range");
        }
    }

    // Input and Output operators
    friend istream& operator>>(istream& is, VideoGameCompany& vgc)
    {
        cout << "Enter employee count: ";
        is >> vgc.employeeCount;

        cout << "Enter annual revenue: ";
        is >> vgc.annualRevenue;

        cout << "Enter number of available games: ";
        int numGames;
        is >> numGames;

        vgc.availableGames.clear(); 

        for (int i = 0; i < numGames; ++i)
        {
            VideoGame game;
            cout << "Enter details for game " << i + 1 << ":" << endl;
            is >> game;
            vgc.availableGames.push_back(game);
        }

        return is;
    }

    friend ostream& operator<<(ostream& os, const VideoGameCompany& vgc)
    {
        os << "Employee Count: " << vgc.employeeCount << endl;
        os << "Annual Revenue: " << vgc.annualRevenue << endl;
        os << "Available Games:" << endl;
        for (const VideoGame& game : vgc.availableGames)
        {
            os << game << endl;
        }

        return os;
    }

    // Destructor
    ~VideoGameCompany()
    {

    }
};


int main() {
    /*VideoGame vg1;
    cin >> vg1;
    cout << vg1 << endl;*/
    
    VideoGame vg2("Overwatch 2", "Online shooter", "PC/Console", 14.99);
    cout << vg2 << endl;

    /*vg1 = vg2;
    cout << vg1 << endl;

    AdventureGame ag1;
    cin >> ag1;
    cout << ag1 << endl;

    AdventureGame ag2("Medium", 6, "Final Fantasy VII", "Adventure", "PC", 23.5);
    cout << ag2 << endl;

    ag1 = ag2;
    cout << ag1 << endl;

    StrategyGame sg1;
    cin >> sg1;
    cout << sg1 << endl;

    StrategyGame sg2("RTS", 4, "Age of Empires", "Strategy", "PC", 29.99);
    cout << sg2 << endl;

    sg1 = sg2;
    cout << sg1 << endl;*/

    VideoGameCompany vgc1;
    cin >> vgc1;
    cout << vgc1;
    cout << endl;

    vgc1 += vg2;
    cout << vgc1;
    cout << endl;

    cout << "Game at index 1:" << endl;
    cout << vgc1[1] << endl;

    vgc1 -= vg2;
    cout << vgc1;
    cout << endl;

    return 0;
}
