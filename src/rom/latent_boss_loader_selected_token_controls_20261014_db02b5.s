; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $02B5
boss_lz_controls_db02b5:
    ; backreference count 3, distance 86
    .byte $80, $55
    ; literal count 3; subsequent asset bytes excluded
    .byte $02
