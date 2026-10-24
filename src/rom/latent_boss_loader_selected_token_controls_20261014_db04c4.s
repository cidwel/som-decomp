; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $04C4
boss_lz_controls_db04c4:
    ; backreference count 6, distance 1305
    .byte $B5, $18
    ; literal count 3; subsequent asset bytes excluded
    .byte $02
