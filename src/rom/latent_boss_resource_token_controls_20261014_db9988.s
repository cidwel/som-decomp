; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $9988
boss_lz_controls_db9988:
    ; backreference count 5, distance 49
    .byte $A0, $30
    ; literal count 10; subsequent asset bytes excluded
    .byte $09
