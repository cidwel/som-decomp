.setcpu "65816"
.segment "CODE"
.org $F4C1
map_control_0cf4c1:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
    .byte $CA ; same-value copy count/distance
