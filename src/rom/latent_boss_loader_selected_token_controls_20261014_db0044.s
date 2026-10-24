; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0044
boss_lz_controls_db0044:
    ; backreference count 4, distance 31
    .byte $90, $1E
    ; literal count 3; subsequent asset bytes excluded
    .byte $02
