.setcpu "65816"
.segment "CODE"
.org $03D7
map_control_0f03d7:
    .byte $C2 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
