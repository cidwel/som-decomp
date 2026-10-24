.setcpu "65816"
.segment "CODE"
.org $87D3
map_control_0e87d3:
    .byte $E0 ; previous-row copy escape
    .byte $8C ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $86 ; row-distance/count
    .byte $E1 ; previous-row copy count
