.setcpu "65816"
.segment "CODE"
.org $6430
map_control_0e6430:
    .byte $CA ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
