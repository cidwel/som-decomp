; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D7FC
boss_lz_controls_dbd7fc:
    ; backreference count 3, distance 207
    .byte $80, $CE
    ; literal count 5; subsequent asset bytes excluded
    .byte $04
