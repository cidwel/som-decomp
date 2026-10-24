.setcpu "65816"
.segment "CODE"
.org $C69A
map_control_0dc69a:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
