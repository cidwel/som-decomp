.setcpu "65816"
.segment "CODE"
.org $0E48
map_control_0f0e48:
    .byte $E6 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
