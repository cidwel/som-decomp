; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B8FE
boss_lz_controls_dbb8fe:
    ; backreference count 3, distance 837
    .byte $83, $44
    ; literal count 17; subsequent asset bytes excluded
    .byte $10
