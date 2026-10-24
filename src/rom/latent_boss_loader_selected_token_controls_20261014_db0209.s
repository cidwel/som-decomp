; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0209
boss_lz_controls_db0209:
    ; backreference count 4, distance 70
    .byte $90, $45
    ; backreference count 3, distance 106
    .byte $80, $69
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
