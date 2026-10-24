; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BA4A
boss_lz_controls_daba4a:
    ; backreference count 3, distance 88
    .byte $80, $57
    ; literal count 4; subsequent asset bytes excluded
    .byte $03
