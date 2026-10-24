; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $92CE
boss_lz_controls_db92ce:
    ; backreference count 5, distance 24
    .byte $A0, $17
    ; literal count 3; subsequent asset bytes excluded
    .byte $02
