; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D2B7
boss_lz_controls_dbd2b7:
    ; backreference count 3, distance 111
    .byte $80, $6E
    ; literal count 40; subsequent asset bytes excluded
    .byte $27
