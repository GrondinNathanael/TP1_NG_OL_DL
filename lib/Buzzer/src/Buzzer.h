
class Buzzer {
    public:
        Buzzer();
        bool ring(int nbParticles);
    private:
        int snoozeCountdown = 0;
        const int RESET_SNOOZE_COUNTDOWN = 1800000; // millisecondes
};
