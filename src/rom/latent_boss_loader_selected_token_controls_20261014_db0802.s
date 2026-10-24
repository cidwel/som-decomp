; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0802
boss_lz_controls_db0802:
    ; backreference count 5, distance 98
    .byte $A0, $61
    ; backreference count 4, distance 2746
    .byte $9A, $B9
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
