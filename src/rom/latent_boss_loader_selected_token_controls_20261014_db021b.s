; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $021B
boss_lz_controls_db021b:
    ; backreference count 5, distance 292
    .byte $A1, $23
    ; literal count 3; subsequent asset bytes excluded
    .byte $02
