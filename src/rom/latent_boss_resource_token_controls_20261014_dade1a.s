; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $DE1A
boss_lz_controls_dade1a:
    ; backreference count 3, distance 624
    .byte $82, $6F
    ; literal count 10; subsequent asset bytes excluded
    .byte $09
