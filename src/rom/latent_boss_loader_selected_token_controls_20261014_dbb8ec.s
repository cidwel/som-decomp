; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B8EC
boss_lz_controls_dbb8ec:
    ; backreference count 4, distance 628
    .byte $86, $73
    ; literal count 15; subsequent asset bytes excluded
    .byte $0E
