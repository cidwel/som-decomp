; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0051
boss_lz_controls_db0051:
    ; backreference count 5, distance 24
    .byte $A0, $17
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
