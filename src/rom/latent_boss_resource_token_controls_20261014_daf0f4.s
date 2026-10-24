; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F0F4
boss_lz_controls_daf0f4:
    ; backreference count 5, distance 363
    .byte $A1, $6A
    ; literal count 8; subsequent asset bytes excluded
    .byte $07
