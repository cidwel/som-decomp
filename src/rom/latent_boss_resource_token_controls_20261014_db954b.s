; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $954B
boss_lz_controls_db954b:
    ; backreference count 3, distance 36
    .byte $80, $23
    ; literal count 33; subsequent asset bytes excluded
    .byte $20
