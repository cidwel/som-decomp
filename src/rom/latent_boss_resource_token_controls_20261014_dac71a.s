; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C71A
boss_lz_controls_dac71a:
    ; backreference count 3, distance 46
    .byte $80, $2D
    ; literal count 4; subsequent asset bytes excluded
    .byte $03
