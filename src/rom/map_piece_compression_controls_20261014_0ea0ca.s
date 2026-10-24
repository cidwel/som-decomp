.setcpu "65816"
.segment "CODE"
.org $A0CA
map_control_0ea0ca:
    .byte $C1 ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $89 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
