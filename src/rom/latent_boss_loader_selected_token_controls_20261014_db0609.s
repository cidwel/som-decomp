; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0609
boss_lz_controls_db0609:
    ; backreference count 5, distance 8
    .byte $A0, $07
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
