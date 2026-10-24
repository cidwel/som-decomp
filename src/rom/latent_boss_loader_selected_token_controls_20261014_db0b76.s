; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0B76
boss_lz_controls_db0b76:
    ; backreference count 4, distance 28
    .byte $90, $1B
    ; literal count 3; subsequent asset bytes excluded
    .byte $02
