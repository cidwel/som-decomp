; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C44A
boss_lz_controls_dbc44a:
    ; backreference count 3, distance 17
    .byte $80, $10
    ; literal count 3; subsequent asset bytes excluded
    .byte $02
