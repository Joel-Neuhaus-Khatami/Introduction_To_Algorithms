import pulp as p

# Definer problemet
model = p.LpProblem('HammersAndNails', p.LpMaximize)

# Her skal du definere beslutningsvariablene
x = p.LpVariable("x", lowBound = 0, upBound=40)
y = p.LpVariable("y", lowBound=0)

# Her skal du legge til den linÃ¦re funksjonen som skal optimeres
model += 3000*x + 1000*y


# Her skal du legge til de lineÃ¦re ulikhetene som pÃ¥ oppfylles
model += 2*x + y <= 100
model += x <= 40
model += x >= 0
model += y >= 0
model += x + 2*y <= 80


# Print modellen
print(model)

# LÃ¸s det lineÃ¦re programmet
status = model.solve()

# Print lÃ¸sningen


# Print verdien til en beslutningsvariabel:
print(p.value(x))

# Print optimal verdi:
print(p.value(model.objective))
