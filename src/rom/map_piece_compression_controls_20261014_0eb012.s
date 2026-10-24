.setcpu "65816"
.segment "CODE"
.org $B012
map_control_0eb012:
    .byte $CA ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
