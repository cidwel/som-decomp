; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0848
boss_lz_controls_db0848:
    ; backreference count 5, distance 1025
    .byte $A4, $00
    ; backreference count 3, distance 1093
    .byte $84, $44
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
