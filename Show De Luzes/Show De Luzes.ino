

unsigned long tempoAnterior=0;

unsigned long tempoMaximo = 1000;

void setup(){

	pinMode(12, OUTPUT);
	pinMode(11, OUTPUT);
	pinMode(10, OUTPUT);
	Serial.begin(9600);

}

void loop(){

	unsigned long tempoAtual = millis();
	// Função para ler o tempo atual

	boolean ledRed, ledOra, ledWhi;

	ledRed = digitalRead(12);
	ledOra = digitalRead(11);
	ledWhi = digitalRead(10);

	if(ledRed==true){
		digitalWrite(12, LOW);
		digitalWrite(11, HIGH);
	}
	else if(ledOra==true){
		digitalWrite(11, LOW);
		digitalWrite(10, HIGH);
	}
	else{
		digitalWrite(10, LOW);
		digitalWrite(12, HIGH);
	}

	while(tempoAtual-tempoAnterior<tempoMaximo){
		tempoAtual = millis();
	}

	tempoAnterior = tempoAtual;

}