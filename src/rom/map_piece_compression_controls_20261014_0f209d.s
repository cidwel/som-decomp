.setcpu "65816"
.segment "CODE"
.org $209D
map_control_0f209d:
    .byte $C5 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
