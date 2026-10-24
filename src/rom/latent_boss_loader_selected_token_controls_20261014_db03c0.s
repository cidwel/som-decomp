; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $03C0
boss_lz_controls_db03c0:
    ; backreference count 7, distance 25
    .byte $C0, $18
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
