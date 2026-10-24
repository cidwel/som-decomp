; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B7AC
boss_lz_controls_dab7ac:
    ; backreference count 3, distance 9
    .byte $80, $08
    ; literal count 32; subsequent asset bytes excluded
    .byte $1F
