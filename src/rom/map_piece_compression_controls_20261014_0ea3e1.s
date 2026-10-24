.setcpu "65816"
.segment "CODE"
.org $A3E1
map_control_0ea3e1:
    .byte $C5 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
