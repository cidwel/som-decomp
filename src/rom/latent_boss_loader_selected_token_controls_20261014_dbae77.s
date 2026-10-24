; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $AE77
boss_lz_controls_dbae77:
    ; backreference count 3, distance 12
    .byte $80, $0B
    ; literal count 3; subsequent asset bytes excluded
    .byte $02
