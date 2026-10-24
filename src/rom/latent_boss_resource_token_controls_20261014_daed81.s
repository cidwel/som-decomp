; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $ED81
boss_lz_controls_daed81:
    ; backreference count 3, distance 28
    .byte $80, $1B
    ; literal count 9; subsequent asset bytes excluded
    .byte $08
