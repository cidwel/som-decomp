; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $983D
boss_lz_controls_db983d:
    ; backreference count 3, distance 81
    .byte $80, $50
    ; literal count 4; subsequent asset bytes excluded
    .byte $03
