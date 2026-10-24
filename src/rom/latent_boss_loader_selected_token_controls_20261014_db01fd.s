; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $01FD
boss_lz_controls_db01fd:
    ; backreference count 5, distance 8
    .byte $A0, $07
    ; literal count 3; subsequent asset bytes excluded
    .byte $02
