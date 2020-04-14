//
// Created by jacek on 2020-04-11.
//

#ifndef BOUT_HELPER_SCORE_HPP
#define BOUT_HELPER_SCORE_HPP


class Score {
private:
    int bigPointFighter1 = 0;
    int smallPointFighter1 = 0;
    int bigPointFighter2 = 0;
    int smallPointFighter2 = 0;
    inline static int pointsDivider = 3;
public:
    Score() = default;
    ~Score() = default;

    //setter
    void setBigPointsFighter1(int bigPoints){ bigPointFighter1 = bigPoints; reload();}
    void setBigPointsFighter2(int bigPoints){ bigPointFighter2 = bigPoints; reload();}
    void setSmallPointsFighter1(int smallPoints){ smallPointFighter1 = smallPoints; reload();}
    void setSmallPointsFighter2(int smallPoints){ smallPointFighter2 = smallPoints; reload();}
    static void setPointsDivider(int pointsDiv){ pointsDivider = pointsDiv; }

    //update --- score += value
    void updateBigPointsFighter1(int value = 1){ bigPointFighter1 += value; reload();}
    void updateBigPointsFighter2(int value = 1){ bigPointFighter2 += value; reload();}
    void updateSmallPointsFighter1(int value = 1){ smallPointFighter1 += value; reload();}
    void updateSmallPointsFighter2(int value = 1){ smallPointFighter2 += value; reload();}

    //getter
    int getBigPointsFighter1(){return bigPointFighter1;}
    int getBigPointsFighter2(){return bigPointFighter2;}
    int getSmallPointsFighter1(){return smallPointFighter1;}
    int getSmallPointsFighter2(){return smallPointFighter2;}
    static int getPointsDivider(){return pointsDivider;}

    void reload();
    void resetPoints();
};


#endif //BOUT_HELPER_SCORE_HPP