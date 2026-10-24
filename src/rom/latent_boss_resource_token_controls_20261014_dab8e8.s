; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B8E8
boss_lz_controls_dab8e8:
    ; backreference count 3, distance 456
    .byte $81, $C7
    ; literal count 10; subsequent asset bytes excluded
    .byte $09
