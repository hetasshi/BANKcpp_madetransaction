#include <iostream>
#include <vector>
#include <string>

// Абстрактный класс для логирования
class Logger {
public:
 virtual void logTransaction(const std::string& message) = 0;
 virtual ~Logger() {}
};

// Логирование в консоль
class ConsoleLogger : public Logger {
public:
 void logTransaction(const std::string& message) override {
  std::cout << "Консоль: " << message << std::endl;
 }
};

// Логирование в файл
class FileLogger : public Logger {
public:
 void logTransaction(const std::string& message) override {
  std::cout << "Файл: " << message << std::endl;
 }
};

// Логирование на принтер
class PrinterLogger : public Logger {
public:
 void logTransaction(const std::string& message) override {
  std::cout << "Принтер: " << message << std::endl;
 }
};

class Bank {
private:
 std::vector<Logger*> loggers;  // Список логгеров

 void performLogging(const std::string& message) {
  for (Logger* logger : loggers) {
   logger->logTransaction(message);
  }
 }

public:
 // Добавление нового логгера
 void addLogger(Logger* newLogger) {
  loggers.push_back(newLogger);
 }

 // Имитация выполнения транзакции
 void madeTransaction() {
  // Выполнение транзакции (имитация)
  std::cout << "Выполнена банковская транзакция!" << std::endl;

  // Логирование информации о транзакции
  performLogging("Произведена транзакция №12345");
 }
};

int main() {
 setlocale(LC_ALL, "Ru");
 Bank bank;

 // Создаем логгеры
 ConsoleLogger console;
 FileLogger file;
 PrinterLogger printer;

 // Настраиваем логирование для банка
 bank.addLogger(&console);
 bank.addLogger(&file);
 bank.addLogger(&printer);

 // Выполняем транзакцию
 bank.madeTransaction();

 return 0;
}
