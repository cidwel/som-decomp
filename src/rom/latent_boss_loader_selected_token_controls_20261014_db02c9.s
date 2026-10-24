; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $02C9
boss_lz_controls_db02c9:
    ; backreference count 3, distance 102
    .byte $80, $65
    ; literal count 4; subsequent asset bytes excluded
    .byte $03
