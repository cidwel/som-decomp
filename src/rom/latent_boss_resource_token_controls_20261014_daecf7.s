; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $ECF7
boss_lz_controls_daecf7:
    ; backreference count 3, distance 445
    .byte $81, $BC
    ; literal count 14; subsequent asset bytes excluded
    .byte $0D
