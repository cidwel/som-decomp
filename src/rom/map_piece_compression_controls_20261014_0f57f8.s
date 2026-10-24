.setcpu "65816"
.segment "CODE"
.org $57F8
map_control_0f57f8:
    .byte $C7 ; same-value copy count/distance
    .byte $E4 ; previous-row copy count
