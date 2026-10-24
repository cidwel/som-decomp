; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BBD4
boss_lz_controls_dabbd4:
    ; backreference count 3, distance 200
    .byte $80, $C7
    ; literal count 3; subsequent asset bytes excluded
    .byte $02
