; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $EDFB
boss_lz_controls_daedfb:
    ; backreference count 4, distance 23
    .byte $90, $16
    ; literal count 5; subsequent asset bytes excluded
    .byte $04
