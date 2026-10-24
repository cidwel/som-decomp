.setcpu "65816"
.segment "CODE"
.org $AECB
map_control_0faecb:
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
    .byte $EE ; backreference distance high bits
    .byte $9A ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
