%{
    
    // Wrtie all C code definitions
    
    // Define all data structures here......
    
    
    
    // Define all global variables here.......

    extern char lex_buffer[512]

    
    char lex_buffer[512];
    
    %}

    %%

// Write all regular expression to generate tokens here.......


    %%

    // C main function

    int main(int argc, char **argv){
        while(1){
            fgets(lex_buffer,sizeof(lex_buffer),stdin);


            // It checks if user presses enter means first character is a new line
            if(lex_buffer[0]=='\n'){
                lex_buffer[0]=0;
                continue;
            }


            yy_scan_string(lex_buffer);
        }
        return 0;
    }