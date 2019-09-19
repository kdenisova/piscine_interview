	// for (int i = 0; i < nbTable; i++)
	// {
	// 	if (tables[i] + people[pos]->time <= totalTime)
	// 	{
	// 		tables[i] += people[pos]->time;
	// 		if (checkPossible(people, tables, nbTable, totalTime, pos + 1) == 1)
	// 			return (1);
	// 		tables[i] -= people[pos]->time;
	// 	}
	// }



// double possiblePrice(int pizzaSize, double *prices, double *max)
// {
// 	double current;

//     if (!pizzaSize)
// 		return (0);
//     for (int i = pizzaSize; i > 0; i--)
// 	{
// 		current = prices[i] + possiblePrice(pizzaSize - i, prices, max);
// 		if (*max < current)
// 			*max = current;
// 	}
// 	return (current);
// }

// void possiblePrice(int pizzaSize, double *prices, double *max, double current)
// {
//     if (!pizzaSize && *max < current)
// 		*max = current;
//     for (int i = pizzaSize; i > 0; i--)
// 		possiblePrice(pizzaSize - i, prices, max, current + prices[i]);
// }