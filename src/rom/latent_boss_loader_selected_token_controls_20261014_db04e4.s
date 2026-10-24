; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $04E4
boss_lz_controls_db04e4:
    ; backreference count 5, distance 1566
    .byte $A6, $1D
    ; literal count 3; subsequent asset bytes excluded
    .byte $02
