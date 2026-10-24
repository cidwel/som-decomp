.setcpu "65816"
.segment "CODE"
.org $230E
map_control_0d230e:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $87 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
