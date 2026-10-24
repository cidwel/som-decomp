; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BAAB
boss_lz_controls_dabaab:
    ; backreference count 11, distance 270
    .byte $A1, $0D
    ; literal count 7; subsequent asset bytes excluded
    .byte $06
