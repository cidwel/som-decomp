.setcpu "65816"
.segment "CODE"
.org $E8C2
map_control_0ee8c2:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $6D ; distance low bit/count
