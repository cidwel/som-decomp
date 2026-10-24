.setcpu "65816"
.segment "CODE"
.org $AAD9
map_control_0faad9:
    .byte $C4 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
