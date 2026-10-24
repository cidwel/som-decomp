; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0B3C
boss_lz_controls_db0b3c:
    ; backreference count 5, distance 93
    .byte $A0, $5C
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
