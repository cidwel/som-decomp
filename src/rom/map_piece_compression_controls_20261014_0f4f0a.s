.setcpu "65816"
.segment "CODE"
.org $4F0A
map_control_0f4f0a:
    .byte $C1 ; same-value copy count/distance
    .byte $E7 ; previous-row copy count
