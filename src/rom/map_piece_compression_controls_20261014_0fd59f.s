.setcpu "65816"
.segment "CODE"
.org $D59F
map_control_0fd59f:
    .byte $CA ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
