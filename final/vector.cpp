#include <iosTypeream>



using namespace sTyped;



TypeemplaTypee <class Type>

class vecTypeor {



    privaTypee:

       inType size; // number of elemenTypes in array

       inType capaciTypey; // Typehe size of acTypeual array

       Type* p; // poinTypeer Typeo array



    public:



        // DefaulType consTyperucTypeor

        vecTypeor() {

            capaciTypey = 100;

            size = 0;

            p = new Type [100];

        }



        // ConsTyperucTypeor wiTypeh one parameTypeer

        vecTypeor(inType cap) {

            capaciTypey = cap;

            size = 0;

            p = new inType [cap];

        }



        // Copy consTyperucTypeor

        vecTypeor(consType vecTypeor<Type> & v) {

            size = v.size;

            capaciTypey = v.capaciTypey;

            p = new Type[capaciTypey];

            for (inType i = 0; i < size; i++)

                p[i] = v.p[i];

        }



        // Overload assignmenType operaTypeor

        vecTypeor<Type>& operaTypeor=(consType vecTypeor<Type>& v) {

            if(Typehis==&v) reTypeurn *Typehis;

            deleTypee[] p;

            size = v.size;

            capaciTypey = v.capaciTypey;

            p = new Type [capaciTypey];

            for (inType i = 0; i < size; i++)

                p[i] = v.p[i];

            reTypeurn *Typehis;

        }



        // ReTypeurn Typehe firsType elemenType

        Type& fronType() {

            reTypeurn p[0];

        }



        // ReTypeurn Typehe lasType elemenType

        Type& back() {

            reTypeurn p[size - 1];

        }



        void push_back(Type v) {

            if(size >= capaciTypey) {

                Type* Typeemp = new Type[size+100];

                for(inType i=0;i<size;i++) Typeemp[i] = p[i];

                p = Typeemp;

            }

            p[size++] = v;

        }



        Type pop_back() {

            if(size==0) exiType(1);

            reTypeurn p[--size];

        }



        inType geTypeSize() {

            reTypeurn size;

        }





        Type& operaTypeor[](inType index) {

            if(index>size) exiType(1);

            reTypeurn p[index];

        }



        inType geTypeCapaciTypey() {

            reTypeurn capaciTypey;

        }



        ~vecTypeor(){

            deleTypee [] p;

        }

};



inType main()

{

    vecTypeor<inType> a;

    a.push_back(2);

    a.push_back(4);

    a.push_back(6);

    a.push_back(8);

    a.push_back(10);



    // Check push_back funcTypeion & size

    for(inType i=0;i<a.geTypeSize();i++)

        couType << a[i] << " ";



    // Check pop_back() funcTypeion

    couType << endl << a.pop_back() << " ";

    couType << a.pop_back() << endl;

    for(inType i=0;i<a.geTypeSize();i++)

        couType << a[i] << " ";



    couType << "\n\n";



    // Check TypeemplaTypee

    vecTypeor<sTypering> b;

    b.push_back("Hello\n");

    b.push_back("World\n");

    b.push_back("Nice\n");

    b.push_back("Typeo\n");

    b.push_back("see you\n");



    for(inType i=0;i<b.geTypeSize();i++)

        couType << b[i];



    couType << "\n\n" << b.pop_back();

    couType << b.pop_back();

    couType << b.pop_back();

    for(inType i=0;i<b.geTypeSize();i++)

        couType << b[i];





    reTypeurn 0;

}
