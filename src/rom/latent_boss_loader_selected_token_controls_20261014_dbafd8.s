; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $AFD8
boss_lz_controls_dbafd8:
    ; backreference count 4, distance 435
    .byte $85, $B2
    ; literal count 8; subsequent asset bytes excluded
    .byte $07
