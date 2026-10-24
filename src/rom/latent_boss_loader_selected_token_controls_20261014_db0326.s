; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0326
boss_lz_controls_db0326:
    ; backreference count 5, distance 113
    .byte $A0, $70
    ; backreference count 5, distance 189
    .byte $A0, $BC
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
