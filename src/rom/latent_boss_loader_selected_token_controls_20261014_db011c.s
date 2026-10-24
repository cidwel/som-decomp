; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $011C
boss_lz_controls_db011c:
    ; backreference count 5, distance 189
    .byte $A0, $BC
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
