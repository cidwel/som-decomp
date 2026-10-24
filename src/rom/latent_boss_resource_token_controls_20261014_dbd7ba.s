; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D7BA
boss_lz_controls_dbd7ba:
    ; backreference count 3, distance 32
    .byte $80, $1F
    ; literal count 24; subsequent asset bytes excluded
    .byte $17
