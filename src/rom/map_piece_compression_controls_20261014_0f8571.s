.setcpu "65816"
.segment "CODE"
.org $8571
map_control_0f8571:
    .byte $CA ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
