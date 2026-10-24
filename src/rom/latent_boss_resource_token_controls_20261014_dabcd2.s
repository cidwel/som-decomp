; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BCD2
boss_lz_controls_dabcd2:
    ; backreference count 3, distance 10
    .byte $80, $09
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
