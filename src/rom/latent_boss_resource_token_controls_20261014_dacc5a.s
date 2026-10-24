; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CC5A
boss_lz_controls_dacc5a:
    ; backreference count 3, distance 1646
    .byte $86, $6D
    ; literal count 128; subsequent asset bytes excluded
    .byte $7F
