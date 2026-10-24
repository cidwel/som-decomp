; Numerical runtime table; comparison and integration pending.
.setcpu "65816"
.segment "CODE"
.org $46EA
mode_seven_scene_signed_rotation_coefficients:
    .word $0000, $0016, $002C, $0042, $0058, $006C, $0080, $0093
    .word $00A5, $00B5, $00C4, $00D2, $00DE, $00E8, $00F1, $00F7
    .word $00FC, $00FF, $0100, $00FF, $00FC, $00F7, $00F1, $00E8
    .word $00DE, $00D2, $00C4, $00B5, $00A5, $0093, $0080, $006C
    .word $0058, $0042, $002C, $0016, $0000, $FFEA, $FFD4, $FFBE
    .word $FFA8, $FF94, $FF80, $FF6D, $FF5B, $FF4B, $FF3C, $FF2E
    .word $FF22, $FF18, $FF0F, $FF09, $FF04, $FF01, $FF00, $FF01
    .word $FF04, $FF09, $FF0F, $FF18, $FF22, $FF2E, $FF3C, $FF4B
    .word $FF5B, $FF6D, $FF80, $FF94, $FFA8, $FFBE, $FFD4, $FFEA
