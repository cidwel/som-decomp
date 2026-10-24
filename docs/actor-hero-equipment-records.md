# Initial hero equipment records

The three near pointers at C04E2B select four-byte item-ID records at C057BD, C057C1 and C057C5. The complete hero initializer reads all four fields into E1E0/E1E1/E1E2/E1E3, also copies the fourth into E1E8, inserts nonzero values from the first three fields into inventory, and inserts the fourth after adding 80.

Typed records preserve the literal initial IDs: boy (0,22,0,9), girl (0,23,0,0), sprite (0,24,0,54). The field order follows the initializer's consumers; no graphics, text or font payload is copied. The zero first/third fields explain why the original initializer skips two conditional inventory calls for every supported hero.

The existing 51-call complete initializer/name proof exercises all three records. It is reused without another original comparison. Independent numeric assembly reconstructs twelve bytes exactly; these count as typed data, separately from instruction-source progress. Source/provenance report: data/actor_hero_equipment_records_numeric.json.
