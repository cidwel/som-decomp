.setcpu "65816"
.segment "CODE"
.org $239A
map_control_0e239a:
    .byte $CA ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
