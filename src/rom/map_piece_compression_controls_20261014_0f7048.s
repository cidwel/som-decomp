.setcpu "65816"
.segment "CODE"
.org $7048
map_control_0f7048:
    .byte $CA ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
