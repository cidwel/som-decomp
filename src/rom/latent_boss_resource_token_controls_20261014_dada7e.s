; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $DA7E
boss_lz_controls_dada7e:
    ; backreference count 11, distance 1
    .byte $C0, $00
    ; literal count 126; subsequent asset bytes excluded
    .byte $7D
