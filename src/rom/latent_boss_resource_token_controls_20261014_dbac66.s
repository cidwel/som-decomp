; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $AC66
boss_lz_controls_dbac66:
    ; backreference count 3, distance 121
    .byte $80, $78
    ; literal count 4; subsequent asset bytes excluded
    .byte $03
