; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $8F4F
boss_lz_controls_db8f4f:
    ; backreference count 3, distance 78
    .byte $80, $4D
    ; literal count 4; subsequent asset bytes excluded
    .byte $03
