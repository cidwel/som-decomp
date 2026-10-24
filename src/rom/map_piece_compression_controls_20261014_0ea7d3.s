.setcpu "65816"
.segment "CODE"
.org $A7D3
map_control_0ea7d3:
    .byte $E0 ; previous-row copy escape
    .byte $34 ; row-distance/count
    .byte $EE ; backreference distance high bits
    .byte $05 ; distance low bit/count
