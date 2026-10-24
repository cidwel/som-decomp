; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0111
boss_lz_controls_db0111:
    ; backreference count 6, distance 8
    .byte $B0, $07
    ; literal count 3; subsequent asset bytes excluded
    .byte $02
