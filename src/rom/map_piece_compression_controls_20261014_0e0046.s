.setcpu "65816"
.segment "CODE"
.org $0046
map_control_0e0046:
    .byte $E5 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
