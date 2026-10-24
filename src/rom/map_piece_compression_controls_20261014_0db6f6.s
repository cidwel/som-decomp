.setcpu "65816"
.segment "CODE"
.org $B6F6
map_control_0db6f6:
    .byte $C1 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
    .byte $CA ; same-value copy count/distance
