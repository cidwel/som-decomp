.setcpu "65816"
.segment "CODE"
.org $E7AC
map_control_0ee7ac:
    .byte $E8 ; backreference distance high bits
    .byte $1B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
