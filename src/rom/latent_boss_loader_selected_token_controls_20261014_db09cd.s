; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $09CD
boss_lz_controls_db09cd:
    ; backreference count 6, distance 738
    .byte $B2, $E1
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
