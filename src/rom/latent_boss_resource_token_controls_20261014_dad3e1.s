; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D3E1
boss_lz_controls_dad3e1:
    ; backreference count 5, distance 1009
    .byte $93, $F0
    ; literal count 30; subsequent asset bytes excluded
    .byte $1D
