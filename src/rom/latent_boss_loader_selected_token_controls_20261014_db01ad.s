; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $01AD
boss_lz_controls_db01ad:
    ; backreference count 5, distance 133
    .byte $A0, $84
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
