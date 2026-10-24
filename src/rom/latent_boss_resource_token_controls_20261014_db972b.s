; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $972B
boss_lz_controls_db972b:
    ; backreference count 3, distance 276
    .byte $81, $13
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
