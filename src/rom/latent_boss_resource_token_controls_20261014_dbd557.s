; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D557
boss_lz_controls_dbd557:
    ; backreference count 5, distance 16
    .byte $88, $0F
    ; literal count 38; subsequent asset bytes excluded
    .byte $25
