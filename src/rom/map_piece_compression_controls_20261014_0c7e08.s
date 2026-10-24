.setcpu "65816"
.segment "CODE"
.org $7E08
map_control_0c7e08:
    .byte $E6 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
