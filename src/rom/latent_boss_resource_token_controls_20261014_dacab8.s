; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CAB8
boss_lz_controls_dacab8:
    ; backreference count 3, distance 959
    .byte $83, $BE
    ; literal count 9; subsequent asset bytes excluded
    .byte $08
