; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $95CF
boss_lz_controls_db95cf:
    ; backreference count 5, distance 1797
    .byte $A7, $04
    ; literal count 22; subsequent asset bytes excluded
    .byte $15
