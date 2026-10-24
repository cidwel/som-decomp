.setcpu "65816"
.segment "CODE"
.org $44EE
map_control_0f44ee:
    .byte $CA ; same-value copy count/distance
    .byte $E7 ; previous-row copy count
