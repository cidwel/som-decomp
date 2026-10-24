.setcpu "65816"
.segment "CODE"
.org $AD68
map_control_0dad68:
    .byte $E8 ; backreference distance high bits
    .byte $14 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $8B ; row-distance/count
    .byte $C3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $87 ; row-distance/count
    .byte $C5 ; same-value copy count/distance
