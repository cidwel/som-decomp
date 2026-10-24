.setcpu "65816"
.segment "CODE"
.org $A53E
map_control_0fa53e:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
    .byte $C6 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $48 ; row-distance/count
    .byte $CD ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $20 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
