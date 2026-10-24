; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BF52
boss_lz_controls_dabf52:
    ; backreference count 4, distance 598
    .byte $86, $55
    ; literal count 10; subsequent asset bytes excluded
    .byte $09
