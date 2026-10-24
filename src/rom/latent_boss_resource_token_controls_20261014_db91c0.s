; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $91C0
boss_lz_controls_db91c0:
    ; backreference count 5, distance 125
    .byte $A0, $7C
    ; literal count 17; subsequent asset bytes excluded
    .byte $10
