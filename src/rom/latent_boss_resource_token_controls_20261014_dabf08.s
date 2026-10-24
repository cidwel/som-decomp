; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BF08
boss_lz_controls_dabf08:
    ; backreference count 3, distance 291
    .byte $81, $22
    ; literal count 3; subsequent asset bytes excluded
    .byte $02
