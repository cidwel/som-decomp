.setcpu "65816"
.segment "CODE"
.org $9A7D
map_control_0d9a7d:
    .byte $CA ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
