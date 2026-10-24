.setcpu "65816"
.segment "CODE"
.org $1713
map_control_0d1713:
    .byte $E8 ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
    .byte $C4 ; same-value copy count/distance
