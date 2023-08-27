# Постановка задачи
## Реализация анализатора для грамматики:

> temp∷=while(expr)temp | print(value);
>
> expr∷=value\<value | value
>
> value∷= ++text | text |  text++ | int

## Пример обрабытываемой структуры:
>
> while(++a\<10)while(a\<b)print(b++)

Остальные возможные варианты представлены в файле Tests.txt
