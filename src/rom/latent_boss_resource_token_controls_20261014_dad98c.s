; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D98C
boss_lz_controls_dad98c:
    ; backreference count 3, distance 186
    .byte $80, $B9
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
