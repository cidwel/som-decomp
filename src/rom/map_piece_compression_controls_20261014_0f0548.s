.setcpu "65816"
.segment "CODE"
.org $0548
map_control_0f0548:
    .byte $C9 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
