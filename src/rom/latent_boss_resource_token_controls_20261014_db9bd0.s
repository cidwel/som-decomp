; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $9BD0
boss_lz_controls_db9bd0:
    ; backreference count 3, distance 93
    .byte $80, $5C
    ; literal count 4; subsequent asset bytes excluded
    .byte $03
