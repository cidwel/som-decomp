.setcpu "65816"
.segment "CODE"
.org $AD38
map_control_0dad38:
    .byte $E8 ; backreference distance high bits
    .byte $12 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
    .byte $C1 ; same-value copy count/distance
