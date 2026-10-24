; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F205
boss_lz_controls_daf205:
    ; backreference count 3, distance 101
    .byte $80, $64
    ; literal count 13; subsequent asset bytes excluded
    .byte $0C
