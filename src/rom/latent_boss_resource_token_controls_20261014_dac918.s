; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C918
boss_lz_controls_dac918:
    ; backreference count 18, distance 1174
    .byte $FC, $95
    ; backreference count 18, distance 1174
    .byte $FC, $95
    ; backreference count 3, distance 15
    .byte $80, $0E
    ; literal count 3; subsequent asset bytes excluded
    .byte $02
