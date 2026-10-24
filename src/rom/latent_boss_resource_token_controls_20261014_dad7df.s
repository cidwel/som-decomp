; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D7DF
boss_lz_controls_dad7df:
    ; backreference count 5, distance 14
    .byte $90, $0D
    ; literal count 7; subsequent asset bytes excluded
    .byte $06
