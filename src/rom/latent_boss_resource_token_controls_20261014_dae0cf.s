; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $E0CF
boss_lz_controls_dae0cf:
    ; backreference count 3, distance 1686
    .byte $86, $95
    ; literal count 5; subsequent asset bytes excluded
    .byte $04
