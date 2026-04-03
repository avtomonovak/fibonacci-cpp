# Fibonacci Calculator with CI/CD on Self-Hosted Runner

## Описание
Программа для вычисления чисел Фибоначчи с CI/CD на self-hosted runner.

## Как работает CI/CD
1. При каждом push в репозиторий запускается GitHub Actions workflow
2. Workflow использует self-hosted runner на Debian
3. Происходит сборка и тестирование программы

## Локальный запуск
```bash
make          # сборка
make test     # тесты
make run      # запуск
