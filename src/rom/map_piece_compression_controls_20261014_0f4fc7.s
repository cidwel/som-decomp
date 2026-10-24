.setcpu "65816"
.segment "CODE"
.org $4FC7
map_control_0f4fc7:
    .byte $C9 ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
