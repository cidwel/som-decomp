; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $DEBA
boss_lz_controls_dadeba:
    ; backreference count 6, distance 1110
    .byte $9C, $55
    ; literal count 5; subsequent asset bytes excluded
    .byte $04
