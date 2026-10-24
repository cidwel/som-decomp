.setcpu "65816"
.segment "CODE"
.org $5F04
map_control_0f5f04:
    .byte $D1 ; same-value copy count/distance
    .byte $E4 ; previous-row copy count
    .byte $C6 ; same-value copy count/distance
