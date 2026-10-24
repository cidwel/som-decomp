; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BC3A
boss_lz_controls_dabc3a:
    ; backreference count 3, distance 55
    .byte $80, $36
    ; literal count 4; subsequent asset bytes excluded
    .byte $03
