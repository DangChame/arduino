while True:

	count = 0
	number = 1
	while number <= 100:
		a = []
		for i in str(number):
			a.append(i)
		if ('7'in a) != 1:
			count += 1
		number += 1
	print(count)
	break



