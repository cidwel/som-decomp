.setcpu "65816"
.segment "CODE"
.org $10B8
map_control_0d10b8:
    .byte $CA ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
