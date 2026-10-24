; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $022B
boss_lz_controls_db022b:
    ; backreference count 5, distance 202
    .byte $A0, $C9
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
