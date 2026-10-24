; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0A9F
boss_lz_controls_db0a9f:
    ; backreference count 5, distance 19
    .byte $A0, $12
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
