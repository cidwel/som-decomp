; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $EB4A
boss_lz_controls_daeb4a:
    ; backreference count 3, distance 121
    .byte $80, $78
    ; literal count 26; subsequent asset bytes excluded
    .byte $19
