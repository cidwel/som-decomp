.setcpu "65816"
.segment "CODE"
.org $C89E
map_control_0dc89e:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
