.setcpu "65816"
.segment "CODE"
.org $57D3
map_control_0d57d3:
    .byte $E8 ; backreference distance high bits
    .byte $13 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
