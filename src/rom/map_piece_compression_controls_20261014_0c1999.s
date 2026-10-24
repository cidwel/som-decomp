.setcpu "65816"
.segment "CODE"
.org $1999
map_control_0c1999:
    .byte $CA ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
