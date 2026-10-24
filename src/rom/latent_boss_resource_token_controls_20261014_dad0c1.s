; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D0C1
boss_lz_controls_dad0c1:
    ; backreference count 4, distance 160
    .byte $88, $9F
    ; literal count 9; subsequent asset bytes excluded
    .byte $08
