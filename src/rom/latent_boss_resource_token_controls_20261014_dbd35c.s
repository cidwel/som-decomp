; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D35C
boss_lz_controls_dbd35c:
    ; backreference count 5, distance 69
    .byte $88, $44
    ; literal count 8; subsequent asset bytes excluded
    .byte $07
