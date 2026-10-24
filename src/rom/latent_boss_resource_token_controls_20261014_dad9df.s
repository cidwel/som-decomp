; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D9DF
boss_lz_controls_dad9df:
    ; backreference count 3, distance 2007
    .byte $87, $D6
    ; literal count 6; subsequent asset bytes excluded
    .byte $05
