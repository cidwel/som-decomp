; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BBF3
boss_lz_controls_dabbf3:
    ; backreference count 3, distance 70
    .byte $80, $45
    ; literal count 10; subsequent asset bytes excluded
    .byte $09
