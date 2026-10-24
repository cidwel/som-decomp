.setcpu "65816"
.segment "CODE"
.org $EECD
map_control_0eeecd:
    .byte $EE ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
