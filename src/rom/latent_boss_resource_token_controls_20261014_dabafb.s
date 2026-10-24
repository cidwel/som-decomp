; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BAFB
boss_lz_controls_dabafb:
    ; backreference count 4, distance 33
    .byte $84, $20
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
