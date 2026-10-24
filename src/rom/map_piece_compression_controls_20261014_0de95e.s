.setcpu "65816"
.segment "CODE"
.org $E95E
map_control_0de95e:
    .byte $C5 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $86 ; row-distance/count
