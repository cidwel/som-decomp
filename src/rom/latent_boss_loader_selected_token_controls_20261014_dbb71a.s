; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B71A
boss_lz_controls_dbb71a:
    ; backreference count 3, distance 21
    .byte $80, $14
    ; literal count 10; subsequent asset bytes excluded
    .byte $09
