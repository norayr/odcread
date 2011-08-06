#ifndef _STORE_H_
#define _STORE_H_

#include <oberon.h>
#include <domain.h>

namespace odc {

	/**
	 * TYPE Store
	 * ABSTRACT
	 * Storable extensible data types like Views.View or TextModels.Text are derived from Store.
	 * Stores are typically allocated by suitable directories, e.g., Views.Directory or TextModels.Directory.
	 * Stores are used as base types for all objects that must be both extensible and persistent.
	 */
	class Store {
	public: 
		static const SHORTCHAR NEWBASE = 0xF0; // (* new base type (level = 0), i.e. not yet in dict *)
		static const SHORTCHAR NEWEXT = 0xF1;  // (* new extension type (level = 1), i.e. not yet in dict *)
		static const SHORTCHAR OLDTYPE = 0xF2; // (* old type, i.e. already in dict *)
		static const SHORTCHAR NIL = 0x80;     // (* nil store *)
		static const SHORTCHAR LINK = 0x81;    // (* link to another elem in same file *)
		static const SHORTCHAR STORE = 0x82;   // (* general store *)
		static const SHORTCHAR ELEM = 0x83;    // (* elem store *)
		static const SHORTCHAR NEWLINK = 0x84; // (* link to another non-elem store in same file *)
		/**
		 * PROCEDURE (s: Store) Domain (): Domain
		 * NEW
		 * A store may be associated with a domain. This is done by the procedure InitDomain, which assigns a domain to the store.
		 * Domain may be called by arbitrary clients.
		 */
		Domain* getDomain();

		/**
		 * PROCEDURE (s: Store) CopyFrom- (source: Store)
		 * NEW, EMPTY
		 * Copy the contents of source to s. Copying is a deep copy.
		 *
		 * Pre
		 * source # NIL	guaranteed
		 * TYP(source) = TYP(s)	guaranteed
		 * s.Domain() = NIL	guaranteed
		 * s is not yet initialized	guaranteed
		 */
		// FIXME
		/**
		 * PROCEDURE (s: Store) Internalize- (VAR rd: Reader)
		 * NEW, EMPTY
		 * (For backward compatibility, this method is actually still EXTENSIBLE. This may change in the future.)
		 * Reads the contents of s from reader rd. Internalize must read the same (amount of) data as is written by the corresponding Externalize procedure.
		 * Internalize is called locally.
		 * Internalize is extended by various persistent object types, e.g., models, views, and controllers.
		 *
		 * Pre
		 * source.Domain() = NIL	guaranteed
		 * source is not yet initialized	guaranteed
		 */
//		 void internalize(Reader &reader) {
//	PROCEDURE (s: Store) Internalize- (VAR rd: Reader), NEW, EXTENSIBLE;
//		VAR thisVersion: INTEGER;
//	BEGIN
//		rd.ReadVersion(minVersion, maxStoreVersion, thisVersion);
//		IF ~rd.cancelled & s.isElem THEN
//			rd.ReadVersion(minVersion, maxStoreVersion, thisVersion)
//			(* works since maxStoreVersion = maxElemVersion = 0 in pre-1.3 *)
//		END	
//	END Internalize;	
//		}

		/**
		 * PROCEDURE (s: Store) Externalize- (VAR wr: Writer)
		 * NEW, EMPTY
		 * (For backward compatibility, this method is actually still EXTENSIBLE. This may change in the future.)
		 * Write the contents of s to writer wr. Externalize must write the same (amount of) data as is read by the corresponding Internalize procedure.
		 * Externalize ist called locally.
		 * Externalize is extended by various persistent object types, e.g., models, views, and controllers.
		 */
		// FIXME

		/**
		 * PROCEDURE (s: Store) ExternalizeAs- (VAR s1: Store)
		 * NEW, EMPTY
		 * Before a store's Externalize procedure is called, its ExternalizeAs procedure is called, which gives the store the opportunity to denote another store that should be externalized in its place (a "proxy"). It is also possible to set s1 to NIL, which means that the store should not be externalized at all. This is used e.g. for compiler error markers, which are never stored.
		 * ExternalizeAs ist called locally.
		 * 
		 * Pre
		 * s1 = s	guaranteed
		 */
		// FIXME
	};

}

#endif // _STORE_H_
