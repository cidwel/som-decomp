; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B8CE
boss_lz_controls_dab8ce:
    ; backreference count 4, distance 457
    .byte $85, $C8
    ; literal count 23; subsequent asset bytes excluded
    .byte $16
