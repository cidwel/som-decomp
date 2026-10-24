; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $030D
boss_lz_controls_db030d:
    ; backreference count 4, distance 142
    .byte $90, $8D
    ; backreference count 4, distance 54
    .byte $90, $35
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
