; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B60B
boss_lz_controls_dbb60b:
    ; backreference count 3, distance 186
    .byte $80, $B9
    ; literal count 10; subsequent asset bytes excluded
    .byte $09
