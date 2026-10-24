.setcpu "65816"
.segment "CODE"
.org $A4D8
map_control_0fa4d8:
    .byte $E4 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
