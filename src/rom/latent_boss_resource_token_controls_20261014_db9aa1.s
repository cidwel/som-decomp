; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $9AA1
boss_lz_controls_db9aa1:
    ; backreference count 3, distance 49
    .byte $80, $30
    ; literal count 3; subsequent asset bytes excluded
    .byte $02
