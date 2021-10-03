
class Buzzer {
    public:
        Buzzer();
        void ring(int nbParticles);
    private:
        int snoozeCountdown = 0;
        const int RESET_SNOOZE_COUNTDOWN = 1800; // secondes
};
