; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $93B1
boss_lz_controls_db93b1:
    ; backreference count 7, distance 65
    .byte $C0, $40
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
