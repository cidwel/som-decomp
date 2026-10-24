; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $00C8
boss_lz_controls_db00c8:
    ; backreference count 5, distance 190
    .byte $A0, $BD
    ; backreference count 3, distance 12
    .byte $80, $0B
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
