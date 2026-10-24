; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0BD0
boss_lz_controls_db0bd0:
    ; backreference count 4, distance 3
    .byte $90, $02
    ; literal count 3; subsequent asset bytes excluded
    .byte $02
