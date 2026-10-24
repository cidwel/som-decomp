.setcpu "65816"
.segment "CODE"
.org $E7B5
map_control_0ee7b5:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
