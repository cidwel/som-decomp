.setcpu "65816"
.segment "CODE"
.org $A044
map_control_0ea044:
    .byte $EA ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
    .byte $C3 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
    .byte $D1 ; same-value copy count/distance
