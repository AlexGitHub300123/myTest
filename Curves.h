#ifndef CURVES_H
#define CURVES_H

class TPoint
{
    public:
        double x;  //point coordinates
        double y;
        double z;
        double x0;  //nullpoint coordinates (center of...)
        double y0;
        double z0;
        double dx; //for second point of derivative of curve
        double dy;
        double dz;
        double t;
        TPoint();
        virtual void SetXYZT(double T);
        virtual void PrintR();
        virtual void PrintNullPoint();
        virtual void PrintPoint();
    protected:
        virtual ~TPoint();
};
//------------------------------------------------------------
class TCircle : public TPoint
{
    double R;

    public:
        TCircle();
        double GetR();
        void SetXYZT(double T) override;
        void PrintNullPoint() override;
        void PrintR() override;
        void PrintPoint() override;
};
//------------------------------------------------------------
class TEllipse : public TPoint
{
    double r;
    double R;

    public:
        TEllipse();
        double GetR();
        double Getr();
        void SetXYZT(double T) override;
        void PrintNullPoint() override;
        void PrintR() override;
        void PrintPoint() override;
};
//-----------------------------------------------------------
class THelix : public TPoint
{
    double R;
    double S; //step of helix

    public:
        THelix();
        double GetR();
        double GetS();
        void SetXYZT(double T) override;
        void PrintNullPoint() override;
        void PrintR() override;
        void PrintPoint() override;
};



#endif
