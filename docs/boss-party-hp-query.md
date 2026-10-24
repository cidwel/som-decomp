# Party HP query

C20989 is a43-byte query that translates the low input A into a party pointer, returns DP C5 for negative actor status, otherwise divides maximum HP184 by current HP182 through the complete existing C22CBF software routine. It right-shifts the quotient once and caps the result at4. This is a maximum/current ratio, not an HP percentage.

When current HP is zero, the divider returnsFFFF without writing quotient56. The caller still reads56, so the query consumes the previous scratch quotient. The new model preserves that result rather than supplying a convenient zero-HP fallback. Prepared29 directed contexts cover all three valid party slots, quotient thresholds1/2/7/8, signed status and five stale56 values when HP is zero. Model-only preflight passes.

Original comparison passed29calls on its first capture after one smoke case. All21own instruction starts and43PC/M/X states are covered;67dependency hashes were revalidated. Full WRAM outside the observed native stack, CPU/context and peripherals agree, including all five stale-quotient HP0 examples. Final evidence is in `data/boss_party_hp_query_audit.json`; model/checker/report/coverage are frozen for source recovery.

D0200/DB7E/M16/X16, binary arithmetic and C5=0 are explicit contracts. The software divider and status pointer arithmetic are reused unchanged; no new tables are needed.
