.setcpu "65816"
.segment "CODE"
.org $A65B
map_control_0ea65b:
    .byte $E3 ; previous-row copy count
    .byte $EA ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
