; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BC74
boss_lz_controls_dbbc74:
    ; backreference count 5, distance 1
    .byte $90, $00
    ; literal count 8; subsequent asset bytes excluded
    .byte $07
