.setcpu "65816"
.segment "CODE"
.org $97D3
map_control_0d97d3:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
