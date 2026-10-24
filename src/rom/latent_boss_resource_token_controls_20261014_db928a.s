; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $928A
boss_lz_controls_db928a:
    ; backreference count 10, distance 1
    .byte $F0, $00
    ; backreference count 6, distance 1
    .byte $B0, $00
    ; literal count 10; subsequent asset bytes excluded
    .byte $09
