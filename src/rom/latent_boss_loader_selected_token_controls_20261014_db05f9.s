; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $05F9
boss_lz_controls_db05f9:
    ; backreference count 4, distance 1031
    .byte $94, $06
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
