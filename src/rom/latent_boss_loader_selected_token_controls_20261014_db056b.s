; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $056B
boss_lz_controls_db056b:
    ; backreference count 4, distance 1225
    .byte $94, $C8
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
