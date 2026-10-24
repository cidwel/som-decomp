.setcpu "65816"
.segment "CODE"
.org $B6F3
map_control_0db6f3:
    .byte $CA ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
