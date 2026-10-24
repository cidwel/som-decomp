.setcpu "65816"
.segment "CODE"
.org $9AE9
map_control_0d9ae9:
    .byte $E3 ; previous-row copy count
    .byte $C6 ; same-value copy count/distance
