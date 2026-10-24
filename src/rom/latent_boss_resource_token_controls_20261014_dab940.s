; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B940
boss_lz_controls_dab940:
    ; backreference count 11, distance 443
    .byte $A1, $BA
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
