; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D36E
boss_lz_controls_dad36e:
    ; backreference count 3, distance 41
    .byte $80, $28
    ; backreference count 3, distance 1019
    .byte $83, $FA
    ; literal count 6; subsequent asset bytes excluded
    .byte $05
