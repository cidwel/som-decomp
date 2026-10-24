; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C4DF
boss_lz_controls_dac4df:
    ; backreference count 3, distance 252
    .byte $80, $FB
    ; literal count 7; subsequent asset bytes excluded
    .byte $06
