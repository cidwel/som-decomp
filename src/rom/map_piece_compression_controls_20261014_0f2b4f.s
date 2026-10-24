.setcpu "65816"
.segment "CODE"
.org $2B4F
map_control_0f2b4f:
    .byte $E5 ; previous-row copy count
    .byte $C3 ; same-value copy count/distance
