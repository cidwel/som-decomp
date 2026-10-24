.setcpu "65816"
.segment "CODE"
.org $FC7A
map_control_0dfc7a:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $C5 ; same-value copy count/distance
