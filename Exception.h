class my_cin: public exception{
    const char* what()
    const throw()
    {//return string
        return "Please Enter 1 2 or 0";
    }
}wrong;

class fail: public exception{
    const char* what()
    const throw()
    {//return string
        return "Please Enter 1 or 2";
    }
}fail;

class wrongpass: public exception{
    const char* what()
    const throw()
    {//return string
        return "Your username or password is wrong";
    }
}failpass;

class wrongchoice: public exception{
    const char* what()
    const throw()
    {//return string
        return "Please Enter Integer";
    }
}failchoice;

class sameid: public exception{
    const char* what()
    const throw()
    {//return string
        return "This ID is not availble";
    }
}sameid;

class MF: public exception{
    const char* what()
    const throw()
    {//return string
        return "Please Enter Only M or F";
    }
}MF;

class strings: public exception{
    const char* what()
    const throw()
    {//return string
        return "Please Enter only string";
    }
}strings;

class ages: public exception{
    const char* what()
    const throw()
    {//return string
        return "Age must be more than 0";
    }
}ages;

class fail4: public exception{
    const char* what()
    const throw()
    {//return string
        return "Please Enter 0 to 5";
    }
}fail14;

class zero: public exception{
    const char* what()
    const throw()
    {//return string
        return "Can't enter 0";
    }
}zero;

class zerox: public exception{
    const char* what()
    const throw()
    {//return string
        return "Please Enter 0";
    }
}zerox;
