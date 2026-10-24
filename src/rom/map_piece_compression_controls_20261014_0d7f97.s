.setcpu "65816"
.segment "CODE"
.org $7F97
map_control_0d7f97:
    .byte $CA ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
