; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $DF38
boss_lz_controls_dadf38:
    ; backreference count 3, distance 118
    .byte $80, $75
    ; literal count 26; subsequent asset bytes excluded
    .byte $19
