.setcpu "65816"
.segment "CODE"
.org $ABB5
map_control_0eabb5:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
