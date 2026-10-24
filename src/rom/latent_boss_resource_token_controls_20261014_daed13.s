; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $ED13
boss_lz_controls_daed13:
    ; backreference count 3, distance 237
    .byte $80, $EC
    ; backreference count 3, distance 165
    .byte $80, $A4
    ; backreference count 3, distance 1672
    .byte $86, $87
    ; backreference count 9, distance 237
    .byte $E0, $EC
    ; literal count 9; subsequent asset bytes excluded
    .byte $08
