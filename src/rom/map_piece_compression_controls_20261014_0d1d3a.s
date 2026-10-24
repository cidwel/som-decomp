.setcpu "65816"
.segment "CODE"
.org $1D3A
map_control_0d1d3a:
    .byte $E8 ; backreference distance high bits
    .byte $19 ; distance low bit/count
    .byte $E1 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $A2 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
