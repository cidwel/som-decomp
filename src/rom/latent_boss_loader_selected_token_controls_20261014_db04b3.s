; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $04B3
boss_lz_controls_db04b3:
    ; backreference count 5, distance 968
    .byte $A3, $C7
    ; literal count 3; subsequent asset bytes excluded
    .byte $02
