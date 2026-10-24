; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D79A
boss_lz_controls_dbd79a:
    ; backreference count 4, distance 310
    .byte $85, $35
    ; literal count 14; subsequent asset bytes excluded
    .byte $0D
