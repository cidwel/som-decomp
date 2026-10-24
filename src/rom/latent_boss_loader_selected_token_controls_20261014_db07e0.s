; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $07E0
boss_lz_controls_db07e0:
    ; backreference count 5, distance 870
    .byte $A3, $65
    ; backreference count 5, distance 2538
    .byte $A9, $E9
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
