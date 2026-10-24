; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CB5C
boss_lz_controls_dacb5c:
    ; backreference count 4, distance 514
    .byte $8A, $01
    ; literal count 7; subsequent asset bytes excluded
    .byte $06
