; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $094D
boss_lz_controls_db094d:
    ; backreference count 3, distance 786
    .byte $83, $11
    ; backreference count 4, distance 1399
    .byte $95, $76
    ; backreference count 4, distance 1108
    .byte $94, $53
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
