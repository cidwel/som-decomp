; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CF4B
boss_lz_controls_dbcf4b:
    ; backreference count 3, distance 2287
    .byte $88, $EE
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
