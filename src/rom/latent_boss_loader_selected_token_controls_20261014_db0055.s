; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0055
boss_lz_controls_db0055:
    ; backreference count 4, distance 24
    .byte $90, $17
    ; literal count 3; subsequent asset bytes excluded
    .byte $02
