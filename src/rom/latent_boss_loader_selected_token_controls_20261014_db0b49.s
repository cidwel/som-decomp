; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0B49
boss_lz_controls_db0b49:
    ; backreference count 4, distance 5
    .byte $90, $04
    ; literal count 3; subsequent asset bytes excluded
    .byte $02
