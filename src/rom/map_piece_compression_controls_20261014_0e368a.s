.setcpu "65816"
.segment "CODE"
.org $368A
map_control_0e368a:
    .byte $C1 ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
