; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0A95
boss_lz_controls_db0a95:
    ; backreference count 4, distance 26
    .byte $90, $19
    ; literal count 3; subsequent asset bytes excluded
    .byte $02
