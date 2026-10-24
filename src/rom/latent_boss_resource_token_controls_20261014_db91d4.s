; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $91D4
boss_lz_controls_db91d4:
    ; backreference count 3, distance 512
    .byte $81, $FF
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
