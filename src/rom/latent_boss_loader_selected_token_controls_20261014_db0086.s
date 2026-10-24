; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0086
boss_lz_controls_db0086:
    ; backreference count 5, distance 39
    .byte $A0, $26
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
