; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CBA1
boss_lz_controls_dacba1:
    ; backreference count 4, distance 226
    .byte $88, $E1
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
