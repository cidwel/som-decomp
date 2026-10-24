; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0AED
boss_lz_controls_db0aed:
    ; backreference count 5, distance 95
    .byte $A0, $5E
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
