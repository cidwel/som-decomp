.setcpu "65816"
.segment "CODE"
.org $93E5
map_control_0e93e5:
    .byte $C5 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
