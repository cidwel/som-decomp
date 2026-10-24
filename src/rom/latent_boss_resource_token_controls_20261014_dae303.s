; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $E303
boss_lz_controls_dae303:
    ; backreference count 3, distance 428
    .byte $81, $AB
    ; literal count 10; subsequent asset bytes excluded
    .byte $09
