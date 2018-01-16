struct node
{
	int number;
	struct node * next;
	struct node * prev;
};

struct node *insert_node( struct node **head, int *value )
{
	//struct node *new_node = NULL;
	struct node *cur_node = NULL;
	int found; /* 1 means found a place to insert the new node in, 0 means not*/
	//new_node = (struct node *)malloc(sizeof(struct node));
	
	if(new_node == NULL)
	{
		printf("memory problem\n");
		exit(1);
	}

	//new_node->number = *value;

/* If the first element */
	if (*head/*list->head*/ == NULL)
	{
		new_node->next = new_node->prev = new_node;
		*head/*list->head*/ = new_node;
	}
	
	
	//Node *temp = list->head;
	else if (new_node->number/*((Patient*)(newNode->data)) -> priorty)*/ < /*((Patient*)(temp->data)) -> priorty)*/(*head)->number)
	{
		new_node->next = *head;
		new_node->prev = /*list->head*/(*head)->prev;
		/*list->head*/(*head)->prev = new_node;
		/*list->head*/*head = new_node;
		/*list->head*/(*head)->prev->next = /*list->head*/*head;
	}
	else
	{
		cur_node = /*list->head*/*head;
		found = 0;
		do
		{
			if( new_node->number/*((Patient*)(newNode->data)) -> priorty)*/ < /*((Patient*)(cur_node->data)) -> priorty)*/cur_node->number )
			{
				found = 1;
				break;
			}
			else
			{
//				last_node = cur_node;
				cur_node = cur_node->next;
			}
		}
		while ( cur_node != /*list->head*/*head );
/* We got the right place to insert our node */
		if( found == 1 )
		{
			new_node->next = cur_node;
			new_node->prev = cur_node->prev;
			cur_node->prev->next = new_node;
			cur_node->prev = new_node;
		}
/* Insert at the tail of the list JUST INSERT BACK*/
		else
		{
			new_node->next = *head;
			new_node->prev = (*head)->prev;
			(*head)->prev->next = new_node;
			(*head)->prev = new_node;
		}
	}
	return *head;
}

int main(void)
{
	
	
	
	
	
	
	
	
	return 0;
}



