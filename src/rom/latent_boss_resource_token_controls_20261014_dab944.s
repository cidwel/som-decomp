; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B944
boss_lz_controls_dab944:
    ; backreference count 3, distance 45
    .byte $80, $2C
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
