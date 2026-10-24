.setcpu "65816"
.segment "CODE"
.org $ABA6
map_control_0daba6:
    .byte $E4 ; previous-row copy count
    .byte $D9 ; same-value copy count/distance
