; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $AC99
boss_lz_controls_dbac99:
    ; backreference count 3, distance 776
    .byte $83, $07
    ; backreference count 4, distance 591
    .byte $86, $4E
    ; literal count 36; subsequent asset bytes excluded
    .byte $23
