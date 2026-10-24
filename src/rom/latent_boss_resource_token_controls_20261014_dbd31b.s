; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D31B
boss_lz_controls_dbd31b:
    ; backreference count 5, distance 1
    .byte $88, $00
    ; literal count 27; subsequent asset bytes excluded
    .byte $1A
