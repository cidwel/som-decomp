.setcpu "65816"
.segment "CODE"
.org $D57E
map_control_0ed57e:
    .byte $E2 ; previous-row copy count
    .byte $EC ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
