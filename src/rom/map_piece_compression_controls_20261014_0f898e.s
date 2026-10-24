.setcpu "65816"
.segment "CODE"
.org $898E
map_control_0f898e:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $2B ; row-distance/count
