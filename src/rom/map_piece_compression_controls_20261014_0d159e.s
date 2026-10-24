.setcpu "65816"
.segment "CODE"
.org $159E
map_control_0d159e:
    .byte $E0 ; previous-row copy escape
    .byte $2B ; row-distance/count
    .byte $C3 ; same-value copy count/distance
