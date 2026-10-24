; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C24E
boss_lz_controls_dac24e:
    ; backreference count 3, distance 445
    .byte $81, $BC
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
