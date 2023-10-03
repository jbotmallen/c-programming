int main()
{
    DICTIONARY d;

    init(d);
    populate(d);
    display(d);

    deleteElem(d, 99);//TRY TO DELETE SOMETHING THAT DOESN'T EXIST
    deleteElem(d, 27); //DELETE SOMETHING
    deleteElem(d, 35);//DELETE AT SOMEWHERE RECENTLY DELETED
    display(d);

    return 0;
}