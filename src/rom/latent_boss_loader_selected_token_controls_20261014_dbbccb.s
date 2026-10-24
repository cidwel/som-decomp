; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BCCB
boss_lz_controls_dbbccb:
    ; backreference count 7, distance 91
    .byte $A0, $5A
    ; backreference count 4, distance 1
    .byte $88, $00
    ; literal count 3; subsequent asset bytes excluded
    .byte $02
