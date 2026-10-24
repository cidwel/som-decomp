.setcpu "65816"
.segment "CODE"
.org $E8D3
map_control_0ee8d3:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
