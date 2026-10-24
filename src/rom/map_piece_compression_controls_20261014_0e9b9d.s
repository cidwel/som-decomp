.setcpu "65816"
.segment "CODE"
.org $9B9D
map_control_0e9b9d:
    .byte $C5 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $A4 ; row-distance/count
    .byte $E1 ; previous-row copy count
