; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BC41
boss_lz_controls_dabc41:
    ; backreference count 3, distance 17
    .byte $80, $10
    ; literal count 4; subsequent asset bytes excluded
    .byte $03
