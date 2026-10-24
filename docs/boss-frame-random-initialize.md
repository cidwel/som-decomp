# Boss RNG native initialization — original comparison complete

The complete RNG draw body C2300B was previously reconstructed with its55-byte pool and two valid indices supplied as direct inputs. C23057 now reconstructs the missing52-byte native initialization routine that produces those inputs. It copies the55 initial seed constants from C2308B into0306..033C and computes first index as the high byte of seed×55 through actual byte multiplication C22AA6. The second index is first+31, subtracting55 at the literal compare branch. Neither the seed table nor indices are invented by this model.

The routine literally executes SEP30 then REP30: it truncates incoming X/Y to bytes, returns M16/X16, preserves the accumulator's high byte across byte operations, and leaves hardware multiplication registers and DP46/4E/56/57 exactly as the original helper. NativeD0200/DB7E/binary and incoming M16/X16 define this directed callback contract; other entry-width/DB/D domains remain separate.

The12 directed seed cases pass model-only preparation:0/1/4/5/111/112/113/127/128/251/252/255. They exercise first-index0→1, offset31 wrapping at first-index24 and upper index54. Original comparison and source-start attribution are complete, as recorded below. Parent source integration remains authoritative. Subsequent actual drawing can now compose from native initialization rather than a manually populated fixture; uninterrupted gameplay RNG usage and timing remain separate.

The55-byte table is regenerated as explicit typed numeric initial seed constants, independently assembling byte-exactly with ca65/ld65. Separate source/generator/report/proposal leave the shared manifest untouched. This is an RNG constant table; no script, palette, image, audio or other asset payload is saved.

All12 original calls passed terminal exit0 on the first capture. Independent audit covers24/24 own starts across37 PC/M/X states. All dependencies revalidated; tools/model/report/coverage frozen. Source proposal52 instruction bytes plus55 independently assembled numeric RNG constants. Integration spec: `boss_frame_random_initialize_proof:boss_frame_random_initialize.RandomInitialize:boss-frame-random-initialize`.

- `tools/boss_frame_random_initialize.py`: `fab64ae09765d03785d3ad57be5d119c6b5ab1b7f85cdcd3548161d0c8e0c583`
- `tools/boss_frame_random_initialize_proof.py`: `4c8e41b99b397b8786cbcd43128ebffb4ef11029f5b2b08df00fb28a0853b262`
- `data/boss_frame_random_initialize_proof.json`: `2938fc317f65465fdcfd3f4cb1689485b6b1fa0bf13a7b1b4cb330dd609a5eea`
- `data/boss_frame_random_initialize_proof.coverage.json`: `24c17cee54866df67daa227f0a6928f8809202fb98b92baf5314babd5f9e2b1b`
