; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $A30C
boss_lz_controls_dba30c:
    ; backreference count 4, distance 978
    .byte $8B, $D1
    ; literal count 8; subsequent asset bytes excluded
    .byte $07
