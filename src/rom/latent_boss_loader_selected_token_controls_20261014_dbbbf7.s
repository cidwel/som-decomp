; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BBF7
boss_lz_controls_dbbbf7:
    ; backreference count 3, distance 1001
    .byte $83, $E8
    ; literal count 7; subsequent asset bytes excluded
    .byte $06
