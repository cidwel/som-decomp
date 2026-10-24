; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D9AB
boss_lz_controls_dad9ab:
    ; backreference count 4, distance 1445
    .byte $8D, $A4
    ; literal count 4; subsequent asset bytes excluded
    .byte $03
