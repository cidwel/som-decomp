.setcpu "65816"
.segment "CODE"
.org $A0DA
map_control_0ea0da:
    .byte $C1 ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
    .byte $C2 ; same-value copy count/distance
