.setcpu "65816"
.segment "CODE"
.org $9017
map_control_0d9017:
    .byte $E5 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
