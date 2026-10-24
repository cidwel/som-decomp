; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D240
boss_lz_controls_dbd240:
    ; backreference count 3, distance 10
    .byte $80, $09
    ; literal count 64; subsequent asset bytes excluded
    .byte $3F
