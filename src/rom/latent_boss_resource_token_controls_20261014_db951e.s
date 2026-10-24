; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $951E
boss_lz_controls_db951e:
    ; backreference count 4, distance 11
    .byte $90, $0A
    ; literal count 3; subsequent asset bytes excluded
    .byte $02
