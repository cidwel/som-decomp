.setcpu "65816"
.segment "CODE"
.org $9B75
map_control_0f9b75:
    .byte $E4 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
