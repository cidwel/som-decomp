; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $07AA
boss_lz_controls_db07aa:
    ; backreference count 6, distance 361
    .byte $B1, $68
    ; backreference count 3, distance 11
    .byte $80, $0A
    ; backreference count 5, distance 1423
    .byte $A5, $8E
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
