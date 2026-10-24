; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $9E0A
boss_lz_controls_db9e0a:
    ; backreference count 3, distance 255
    .byte $80, $FE
    ; literal count 3; subsequent asset bytes excluded
    .byte $02
