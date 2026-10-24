.setcpu "65816"
.segment "CODE"
.org $A04C
map_control_0ea04c:
    .byte $C6 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
    .byte $EA ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
