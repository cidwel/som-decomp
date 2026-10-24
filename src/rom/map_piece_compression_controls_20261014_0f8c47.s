.setcpu "65816"
.segment "CODE"
.org $8C47
map_control_0f8c47:
    .byte $C4 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
