; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $06E7
boss_lz_controls_db06e7:
    ; backreference count 5, distance 9
    .byte $A0, $08
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
