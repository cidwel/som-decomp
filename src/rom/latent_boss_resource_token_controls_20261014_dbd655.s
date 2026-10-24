; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D655
boss_lz_controls_dbd655:
    ; backreference count 8, distance 101
    .byte $94, $64
    ; literal count 7; subsequent asset bytes excluded
    .byte $06
