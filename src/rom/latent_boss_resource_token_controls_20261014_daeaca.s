; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $EACA
boss_lz_controls_daeaca:
    ; backreference count 3, distance 1289
    .byte $85, $08
    ; literal count 110; subsequent asset bytes excluded
    .byte $6D
