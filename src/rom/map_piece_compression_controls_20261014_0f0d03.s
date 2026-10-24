.setcpu "65816"
.segment "CODE"
.org $0D03
map_control_0f0d03:
    .byte $C5 ; same-value copy count/distance
    .byte $E6 ; previous-row copy count
