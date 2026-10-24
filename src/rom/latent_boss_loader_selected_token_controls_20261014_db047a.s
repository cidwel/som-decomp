; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $047A
boss_lz_controls_db047a:
    ; backreference count 5, distance 182
    .byte $A0, $B5
    ; backreference count 3, distance 643
    .byte $82, $82
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
