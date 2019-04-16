/* ************************************************************************** */
/** Descriptive File Name

  @Company
    Company Name

  @File Name
    filename.h

  @Summary
    Brief description of the file.

  @Description
    Describe the purpose of this file.
 */
/* ************************************************************************** */

#ifndef _EXAMPLE_FILE_NAME_H    /* Guard against multiple inclusion */
#define _EXAMPLE_FILE_NAME_H


/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */

/* This section lists the other files that are included in this file.
 */

/* TODO:  Include other files here if needed. */


/* Provide C++ Compatibility */
#ifdef __cplusplus
extern "C" {
#endif


    /* ************************************************************************** */
    /* ************************************************************************** */
    /* Section: Constants                                                         */
    /* ************************************************************************** */
    /* ************************************************************************** */

    /*  A brief description of a section can be given directly below the section
        banner.
     */

uint8_t lut_ultra[256] = {5,5,5,5,5,5,5,17,20,22,25,27,30,32,35,38,40,43,45,48,50,53,55,58,60,63,66,68,71,73,76,78,81,83,86,88,91,93,96,99,101,104,106,109,111,114,116,119,121,124,126,129,132,134,137,139,142,144,147,149,152,154,157,159,162,165,167,170,172,175,177,180,182,185,187,190,193,195,198,200,203,205,208,210,213,215,218,220,223,226,228,231,233,236,238,241,243,246,248,251,253,256,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254 ,254};
    /* ************************************************************************** */
    /** Descriptive Constant Name

      @Summary
        Brief one-line summary of the constant.
    
      @Description
        Full description, explaining the purpose and usage of the constant.
        <p>
        Additional description in consecutive paragraphs separated by HTML 
        paragraph breaks, as necessary.
        <p>
        Type "JavaDoc" in the "How Do I?" IDE toolbar for more information on tags.
    
      @Remarks
        Any additional remarks
     */
#define EXAMPLE_CONSTANT 0


    // *****************************************************************************
    // *****************************************************************************
    // Section: Data Types
    // *****************************************************************************
    // *****************************************************************************

    /*  A brief description of a section can be given directly below the section
        banner.
     */


    // *****************************************************************************

    /** Descriptive Data Type Name

      @Summary
        Brief one-line summary of the data type.
    
      @Description
        Full description, explaining the purpose and usage of the data type.
        <p>
        Additional description in consecutive paragraphs separated by HTML 
        paragraph breaks, as necessary.
        <p>
        Type "JavaDoc" in the "How Do I?" IDE toolbar for more information on tags.

      @Remarks
        Any additional remarks
        <p>
        Describe enumeration elements and structure and union members above each 
        element or member.
     */
    typedef struct _example_struct_t {
        /* Describe structure member. */
        int some_number;

        /* Describe structure member. */
        bool some_flag;

    } example_struct_t;


    // *****************************************************************************
    // *****************************************************************************
    // Section: Interface Functions
    // *****************************************************************************
    // *****************************************************************************

    /*  A brief description of a section can be given directly below the section
        banner.
     */

    // *****************************************************************************
    /**
      @Function
        int ExampleFunctionName ( int param1, int param2 ) 

      @Summary
        Brief one-line description of the function.

      @Description
        Full description, explaining the purpose and usage of the function.
        <p>
        Additional description in consecutive paragraphs separated by HTML 
        paragraph breaks, as necessary.
        <p>
        Type "JavaDoc" in the "How Do I?" IDE toolbar for more information on tags.

      @Precondition
        List and describe any required preconditions. If there are no preconditions,
        enter "None."

      @Parameters
        @param param1 Describe the first parameter to the function.
    
        @param param2 Describe the second parameter to the function.

      @Returns
        List (if feasible) and describe the return values of the function.
        <ul>
          <li>1   Indicates an error occurred
          <li>0   Indicates an error did not occur
        </ul>

      @Remarks
        Describe any special behavior not described above.
        <p>
        Any additional remarks.

      @Example
        @code
        if(ExampleFunctionName(1, 2) == 0)
        {
            return 3;
        }
     */
    int ExampleFunction(int param1, int param2);


    /* Provide C++ Compatibility */
#ifdef __cplusplus
}
#endif

#endif /* _EXAMPLE_FILE_NAME_H */

/* *****************************************************************************
 End of File
 */
