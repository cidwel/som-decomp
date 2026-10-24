; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $DBE6
boss_lz_controls_dadbe6:
    ; backreference count 3, distance 229
    .byte $80, $E4
    ; literal count 128; subsequent asset bytes excluded
    .byte $7F
