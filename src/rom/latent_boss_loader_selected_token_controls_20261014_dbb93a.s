; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B93A
boss_lz_controls_dbb93a:
    ; backreference count 3, distance 452
    .byte $81, $C3
    ; literal count 26; subsequent asset bytes excluded
    .byte $19
