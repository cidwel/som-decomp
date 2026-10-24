; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $9730
boss_lz_controls_db9730:
    ; backreference count 3, distance 31
    .byte $80, $1E
    ; literal count 3; subsequent asset bytes excluded
    .byte $02
