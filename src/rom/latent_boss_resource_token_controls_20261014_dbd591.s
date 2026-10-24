; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D591
boss_lz_controls_dbd591:
    ; backreference count 3, distance 888
    .byte $83, $77
    ; backreference count 3, distance 812
    .byte $83, $2B
    ; literal count 29; subsequent asset bytes excluded
    .byte $1C
