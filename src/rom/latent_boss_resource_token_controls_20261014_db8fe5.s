; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $8FE5
boss_lz_controls_db8fe5:
    ; backreference count 4, distance 256
    .byte $90, $FF
    ; literal count 89; subsequent asset bytes excluded
    .byte $58
