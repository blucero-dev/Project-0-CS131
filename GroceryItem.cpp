// GroceryItem Implementation file
// Brian Lucero
// CS131
// part 0
// spring 2020 - started on 2/3/2020


// ===================== N O T E S ============================================
// 1. need to finish constructors, figure out default and non default, and
//    to simply finish figuring out how to Initialize.
// 2. IF you hit a snag, just try to keep building other things, then return later
// 3. start the relational OPERATORS ( finsihed bottom portion )
// 4. finish friend relational operators and insertion/extraction OPERATORS
// 5. ...

// ============================================================================



// -------- GroceryItem class implementation ----------------



// private: (data members)
// ------Initialize data members using "Member Initialization"-------------
// how do i use member intialization in def ctor if the default constructor uses the default keyword.
// is there a way to edit the def constructor?

// public:
// ~~~~~~~~~~~~~~~~~~~~~~~~~~ Constructors ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// default constructor (no args)
// CANT USE THIS: ---------------------------------------------------------
// GroceryItem::GroceryItem() :
        // GroceryItem("Tomato Ketchup - 2 ct", "Heinz", "00051600080015", 0.0) {}
// cant use this because default keyword doesnt allow us intialize the
// data members of the class within the default constructor
// -----------------------------------------------------------------------

// ALL-parameter non-default constructor
// this constructor utilizes constructor initliazation list,
GroceryItem::GroceryItem( const std::string & productName,
                          const std::string & brandName,
                          const std::string & upcCode,
                          double              price )
              :  _productName(productName),
                 _brandName(brandName),
                 _upcCode(upcCode),
                 _price(price) {}
// Multi-Argument Constructors ----------------------------------------
// cant be used : -----------------------------------------
// 1 parameter constructor
GroceryItem::GroceryItem(const std::string & productName)
            : GroceryItem(productName, "brand name", "00000000000000", 0.0) {}
// 2 parameter constructor
GroceryItem::GroceryItem(const std::string & productName,
                         const std::string & brandName)
            : GroceryItem(productName, brandName, "00000000000000", 0.0) {}
// 3 parameter constructor
GroceryItem::GroceryItem( const std::string & productName,
             const std::string & brandName,
             const std::string & upcCode)
            : GroceryItem(productName, brandName, upcCode, 0.0) {}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~ CONSTRUCTORS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// ============================ accessors and mutators ========================
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
// ====================== end of accessors and mutators ==============================


// ================= RELATIONAL OPERATORS ===================================
// = = = = = = = = = = = = = = D O N E = = = = = = = = = = = = = = = = = = = = =
bool operator==( const GroceryItem & lhs, const GroceryItem & rhs ) {
  return ( lhs.upcCode() == rhs.upcCode() && lhs.brandName() == rhs.brandName()
           lhs.productName() == rhs.productName() && lhs.price() == rhs.price() );
}

bool operator!=( const GroceryItem & lhs, const GroceryItem & rhs ) {
  return (!(lhs == rhs));
}

bool operator< ( const GroceryItem & lhs, const GroceryItem & rhs ) {

    bool master;
    int case = 0;
    // case 0 : if lhs_upcCode is false, figure out if upcCodes are equal
    // case 1 : if upcCodes are equal
    // case 2 : if brandNames are equal
    // case 3 ; if productNames are equal
    // idea 1 ------------------------

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

// Since I have already defined the less-than and equality relational operators,
// I am simply using those operators to build the definitions for the following operators

bool operator<=( const GroceryItem & lhs, const GroceryItem & rhs ) {
  return ( lhs < rhs || lhs == rhs );
}

bool operator> ( const GroceryItem & lhs, const GroceryItem & rhs ) {
  return (!(lhs < rhs) && !(lhs == rhs));
}

bool operator>=( const GroceryItem & lhs, const GroceryItem & rhs ) {
  return ( lhs > rhs || lhs == rhs );
}
// ======================== end of RELATIONAL OPERATORS ==============================
// ======================== E N D  of  GroceryItem class =============================
