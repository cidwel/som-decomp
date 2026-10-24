; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $A3F3
boss_lz_controls_dba3f3:
    ; backreference count 3, distance 496
    .byte $81, $EF
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
