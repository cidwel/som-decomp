.setcpu "65816"
.segment "CODE"
.org $A05F
map_control_0ea05f:
    .byte $EA ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
    .byte $C2 ; same-value copy count/distance
