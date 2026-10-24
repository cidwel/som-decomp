.setcpu "65816"
.segment "CODE"
.org $B847
map_control_0fb847:
    .byte $D1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $2B ; row-distance/count
