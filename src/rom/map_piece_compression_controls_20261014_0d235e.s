.setcpu "65816"
.segment "CODE"
.org $235E
map_control_0d235e:
    .byte $CA ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
