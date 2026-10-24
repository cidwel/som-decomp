; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $EF50
boss_lz_controls_daef50:
    ; backreference count 3, distance 279
    .byte $81, $16
    ; literal count 14; subsequent asset bytes excluded
    .byte $0D
