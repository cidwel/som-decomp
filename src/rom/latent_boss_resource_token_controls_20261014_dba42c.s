; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $A42C
boss_lz_controls_dba42c:
    ; backreference count 3, distance 325
    .byte $81, $44
    ; backreference count 4, distance 1304
    .byte $8D, $17
    ; literal count 10; subsequent asset bytes excluded
    .byte $09
