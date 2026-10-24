; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $A243
boss_lz_controls_dba243:
    ; backreference count 5, distance 216
    .byte $90, $D7
    ; literal count 16; subsequent asset bytes excluded
    .byte $0F
