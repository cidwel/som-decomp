; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $A32C
boss_lz_controls_dba32c:
    ; backreference count 4, distance 21
    .byte $88, $14
    ; literal count 5; subsequent asset bytes excluded
    .byte $04
