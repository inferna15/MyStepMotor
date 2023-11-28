class Stepmotor
{
    private:
        int pin1;
        int pin2;
        int pin3;
        int pin4;
        int ms = 10000;
        int speed = 1;
        int direction = 1;
        int step = 1;
        int position = 0;
    public:
        Stepmotor(int pin1, int pin2, int pin3, int pin4){
            this->pin1 = pin1;
            this->pin2 = pin2;
            this->pin3 = pin3;
            this->pin4 = pin4;
            pinMode(pin1, OUTPUT);
            pinMode(pin2, OUTPUT);
            pinMode(pin3, OUTPUT);
            pinMode(pin4, OUTPUT);
        }
        void setSpeed(int speed){
            this->speed = speed;
        }
        void setDirection(int direction){
            this->direction = direction;
        }
        void setStep(int step){
            this->step = step;
        } 
        void start(){
            int pins[] = {pin1, pin2, pin3, pin4};
            while(1){
                if (direction == 1){
                    position = (position + step) % 8;
                }
                if (direction == -1){
                    if (position >= step){
                        position = (position - step) % 8; 
                    }
                    else{
                        position = (8 + position - step) % 8;
                    }
                }
                if(position%2 == 0){
                    digitalWrite(pins[position / 2], HIGH);
                    delay(ms / speed);
                    digitalWrite(pins[position / 2], LOW);
                }
                if(position%2 == 1){
                    digitalWrite(pins[position / 2], HIGH);
                    digitalWrite(pins[((position / 2) + 1) % 4], HIGH);
                    delay(ms / speed);
                    digitalWrite(pins[position / 2], LOW);
                    digitalWrite(pins[((position / 2) + 1) % 4], LOW);
                }  
            }
        }     
};
