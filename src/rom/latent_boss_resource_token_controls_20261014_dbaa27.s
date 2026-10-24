; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $AA27
boss_lz_controls_dbaa27:
    ; backreference count 3, distance 55
    .byte $80, $36
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
