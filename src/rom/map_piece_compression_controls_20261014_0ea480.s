.setcpu "65816"
.segment "CODE"
.org $A480
map_control_0ea480:
    .byte $EA ; backreference distance high bits
    .byte $0A ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
