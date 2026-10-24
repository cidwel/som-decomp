; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $EAB3
boss_lz_controls_daeab3:
    ; backreference count 4, distance 80
    .byte $90, $4F
    ; literal count 3; subsequent asset bytes excluded
    .byte $02
