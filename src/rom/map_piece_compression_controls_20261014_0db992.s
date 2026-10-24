.setcpu "65816"
.segment "CODE"
.org $B992
map_control_0db992:
    .byte $CA ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
