; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D3A3
boss_lz_controls_dad3a3:
    ; backreference count 3, distance 504
    .byte $81, $F7
    ; literal count 31; subsequent asset bytes excluded
    .byte $1E
