; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $00E4
boss_lz_controls_db00e4:
    ; backreference count 5, distance 41
    .byte $A0, $28
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
