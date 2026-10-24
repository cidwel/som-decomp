; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $ED3B
boss_lz_controls_daed3b:
    ; backreference count 5, distance 63
    .byte $A0, $3E
    ; backreference count 5, distance 15
    .byte $A0, $0E
    ; backreference count 10, distance 1
    .byte $F0, $00
    ; literal count 3; subsequent asset bytes excluded
    .byte $02
