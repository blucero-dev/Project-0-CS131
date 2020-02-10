// GroceryItem Implementation file
// Brian Lucero
// CS131
// part 0
// spring 2020 - started on 2/3/2020


// ===================== N O T E S ============================================
// 1. STILL need to finish constructor, figure out non default when user tries
//    to intitialize with only a double type argument (will not compile)
// 2. IF you hit a snag, just try to keep building other things, then return later
// 3. test the relational OPERATORS ( finsihed bottom portion )
// 4. finish and test friend relational operators and insertion/extraction OPERATORS
// 5. ...
// ============================================================================



// ============================================================================
// ================ S T A R T  of  GroceryItem class ==========================
// ============================================================================



// private: (data members)
// std::string _upcCode;
// std::string _brandName;
// std::string _productName;
// double      _price = 0.0;

// public:
// Insertion and Extraction Operators =========================================
// ---------- W I P ------------

// insertion
// needs to tested, and edited so it redirects to "output.txt "file ---------------------
friend std::ostream & operator<<( std::ostream & stream, const GroceryItem & groceryItem ) {
  std::string upcCodeCopy = groceryItem.upcCode();
  std::string brandNameCopy = groceryItem.brandName();
  std::string productNameCopy = groceryItem.productName();
  double priceCopy = groceryItem.price();
  stream << "\"" << upcCodeCopy <<  "\", "
         << "\"" << brandNameCopy << "\", "
         << "\"" << productNameCopy << "\", "
         << priceCopy;
  return stream;
}

// extraction
friend std::istream & operator>>( std::istream & stream,       GroceryItem & groceryItem ) {
  // idea 1 ---------------------------
  std::stringstream ss;
  std::string in;
  std::string out;

  std::string str_arg[4];
  std::string str_to_double_tempVal;
  double newly_converted_double_val = 0.0;

  unsigned int par_num = 0;
  unsigned int com_num = 0;
  unsigned int per_num = 0;

  unsigned int max_par = 6; // 2 parentheses per string
  unsigned int max_com = 3; // 3 commas to separate 4 values

  bool no_par = false;
  bool no_com = false;
  bool no_per = false;

  bool one_arg = false;
  bool two_arg = false;
  bool three_arg = false;
  bool four_arg = false;

  // step 1: read in values on a single line only
  std::getline(std::cin, in); // reads in whole line

  // step 2: a. determine how many strings
  //         b. determine if there is a price value
  //         c. determine which constructor to use based off of a. nd b.
  // Now, we need to determine what can be used to build our dog object
  for (int i = 0; i < in.size(); ++i) { // loop to check how many par, com, per
    bool is_par = false;
    bool is_com = false;
    bool is_per = false;

    std::string chctr;
    chctr = in.at(i);

    if (chctr == "\"") {
      par_num++;
      is_par = true;
    } else if (chctr == ",") {
      com_num++;
      is_com = true;
    } else if (chctr == ".") {
      per_num++;
      is_per = true;
    }
  }




  //  ----- cout values to test if functional - FUNCTIONAL
  // std::cout << "-------- S H O W --------" << "\n\n";
  // std::cout << "par_num = " << par_num << "\n";
  // std::cout << "com_num = " << com_num << "\n";
  // std::cout << "per_num = " << per_num << "\n";

  // step 3: separate the string appropriately
  // NOW, to develop a system that divides up the string
  // into appropriate data type and prepares them so that dog class members
  // can initiliaze to the new values



  // quoted -----------------
  ss << std::quoted(in);
  std::cout << "read in     [" << in << "]\n"
           << "stored as   [" << ss.str() << "]\n";

  ss >> std::quoted(out);
  std::cout << "written out [" << out << "]\n";

  // end of idea 1 -----------------------
  return stream; // apparently this is needed, otherwise:
                // Illegal instruction (core dumped)
}
// ============= end of Insertion/Extraction operators =======================================


// Relational Operators ( inside the class ) ==================================
// -------------- need to be tested -----------------

// equality operator
friend bool operator==( const GroceryItem & lhs, const GroceryItem & rhs ) {
  return ( lhs.upcCode() == rhs.upcCode() && lhs.brandName() == rhs.brandName()
          lhs.productName() == rhs.productName() && lhs.price() == rhs.price() );
  // returns true, IF ALL object members are equal
  // otherwise, returns false
}

// Less-Than operator:
friend bool operator< ( const GroceryItem & lhs, const GroceryItem & rhs ) {
  // very important operator definition to build otherwise
  // important for sorting, needs to be bullet proof
  // aka compare member values correctly

  // idea 1 ------------------------
  bool master;
  int case = 0;
  // case 0 : if lhs_upcCode is false, figure out if upcCodes are equal
  // case 1 : if upcCodes are equal
  // case 2 : if brandNames are equal
  // case 3 ; if productNames are equal

  bool lhs_upcCode = (lhs.upcCode() < rhs.upcCode());
  if (lhs_upcCode) {
    master = true;
  } else {
    bool rhs_upcCode = (rhs.upcCode() < lhs.upcCode());
    bool upcCode_is_equal = (lhs_upcCode == false && rhs_upcCode == false);
    if ( upcCode_is_equal ) {
      case = 1;
    } else {
      master = false;
    }
  }

  if (case == 1) {
    bool lhs_brandName = (lhs.brandName() < rhs.brandName());
    if (lhs_brandName) {
      master = true;
    } else {
      bool rhs_brandName = (rhs.brandName() < lhs.brandName());
      bool brandName_is_equal = (lhs_brandName == false && rhs_brandName == false);
      if ( brandName_is_equal ) {
        case = 2;
      } else {
        master = false;
      }
    }
  }

  if (case == 2) {
    bool lhs_productName = (lhs.productName() < rhs.productName());
    if (lhs_productName) {
      master = true;
    } else {
      bool rhs_productName = (rhs.productName() < lhs.productName());
      bool productName_is_equal = (lhs_productName == false && rhs_productName == false);
      if ( productName_is_equal ) {
        case = 3;
      } else {
        master = false;
      }
    }
  }

  if (case == 3) {
    bool lhs_price = (lhs.price() < rhs.product());
    if (lhs_price) {
      master = true;
    } else {
      master = false;
    }
  return master;
  }
}
// =========== end of relational operators (inside class) =====================


// ====================== CONSTRUCTORS ========================================

// ------Initialize data members using "Member Initialization"-------------
// how do i use member init./ ctor init list, in def ctor if the default constructor uses
// the default keyword.

// is there a way to edit the def constructor?
// ANSWER : NO, def ctor is not editable outside of the header file.
//          Although the def ctor default builds the object
//          with wack values, you cannot edit this unless the user provides at least
//          one argument when creating the object, so that the non-default constructor is called
//          instead of the deafult ctor


// default constructor (no args)
// CANT USE THIS: ---------------------------------------------------------
// GroceryItem::GroceryItem() :
        // GroceryItem("Tomato Ketchup - 2 ct", "Heinz", "00051600080015", 0.0) {}
// cant use this because default keyword doesnt allow us intialize the
// data members of the class within the default constructor
// -----------------------------------------------------------------------

// Multi-Argument Constructors ----------------------------------------

// cant be used : -----------------------------------------
// 1 parameter constructor
// GroceryItem::GroceryItem(const std::string & productName)
//             : GroceryItem(productName, "brand name", "00000000000000", 0.0) {}
// 2 parameter constructor
// GroceryItem::GroceryItem(const std::string & productName,
//                          const std::string & brandName)
//            : GroceryItem(productName, brandName, "00000000000000", 0.0) {}
// 3 parameter constructor
// GroceryItem::GroceryItem( const std::string & productName,
//              const std::string & brandName,
//               const std::string & upcCode)
//                           : GroceryItem(productName, brandName, upcCode, 0.0) {}

// ---------------- S O L U T I O N -------------------------------------------
// notice how you only need to define one constructor because, the last 3 arguments
// in the header file are given default values if not all 4 are given when
// creating an object :

// ALL-parameter non-default constructor
// this ctor utilizes ctor initialization list, and member initialization
// no initialization in ctor body
GroceryItem::GroceryItem( const std::string & productName,
                          const std::string & brandName,
                          const std::string & upcCode,
                          double              price )
              :  _productName(productName),
                 _brandName(brandName),
                 _upcCode(upcCode),
                 _price(price) {}

// also note, the default constructor does not need to be Defined
// because it already has been defined in the header file
// ======================= end of CONSTRUCTORS ================================


// ===================== accessors and mutators ===============================
// = = = = = = = = = = = = = = = D O N E = = = = = = = = = = = = = = = =  = = = =
// Queries (Accessors) --------------------------------------------------
std::string GroceryItem::upcCode     () const { return _upcCode; }
std::string GroceryItem::brandName   () const { return _brandName; }
std::string GroceryItem::productName () const { return _productName; }
double      GroceryItem::price       () const { return _price; }

// Mutators -------------------------------------------------------
void GroceryList::upcCode      ( const std::string & upcCode     ) { _upcCode = upcCode; }
void GroceryList::brandName    ( const std::string & brandName   ) { _brandName = brandName; }
void GroceryList::productName  ( const std::string & productName ) { _productName = productName; }
void GroceryList::price        ( double              price       ) { _price = price; }
// ====================== end of accessors and mutators =======================


// ============ RELATIONAL OPERATORS (outside of class) =======================
// -------------- needs to be tested ----------------

// Since I have already defined the less-than and equality relational operators:
//     -- " friend bool operator< (), friend bool operator==() " --
// I am simply using those operators to build the definitions for the following operators

// == and !=
bool operator==( const GroceryItem & lhs, const GroceryItem & rhs ) {
  return ( lhs == rhs );
}

bool operator!=( const GroceryItem & lhs, const GroceryItem & rhs ) {
  return ( !(lhs == rhs) );
}


// <, <=, >, >=
bool operator< ( const GroceryItem & lhs, const GroceryItem & rhs ) {
  return ( lhs < rhs );
}

bool operator<=( const GroceryItem & lhs, const GroceryItem & rhs ) {
  return ( lhs < rhs || lhs == rhs );
}

bool operator> ( const GroceryItem & lhs, const GroceryItem & rhs ) {
  return ( !(lhs < rhs) && !(lhs == rhs) );
  // if LHS is less-than OR equal to rhs, will return false
}

bool operator>=( const GroceryItem & lhs, const GroceryItem & rhs ) {
  return ( lhs > rhs || lhs == rhs );
}
// ======== end of RELATIONAL OPERATORS (outside of class) ====================


// ============================================================================
// =================== E N D  of  GroceryItem class ===========================
// ============================================================================
