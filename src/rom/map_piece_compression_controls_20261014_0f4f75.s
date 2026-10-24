.setcpu "65816"
.segment "CODE"
.org $4F75
map_control_0f4f75:
    .byte $C4 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
