.setcpu "65816"
.segment "CODE"
.org $C798
map_control_0ec798:
    .byte $C5 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
