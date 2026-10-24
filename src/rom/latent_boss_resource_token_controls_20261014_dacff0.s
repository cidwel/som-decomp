; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CFF0
boss_lz_controls_dacff0:
    ; backreference count 3, distance 206
    .byte $80, $CD
    ; literal count 9; subsequent asset bytes excluded
    .byte $08
