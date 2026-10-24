.setcpu "65816"
.segment "CODE"
.org $B13E
map_control_0db13e:
    .byte $E1 ; previous-row copy count
    .byte $DD ; same-value copy count/distance
