.setcpu "65816"
.segment "CODE"
.org $6111
map_control_0f6111:
    .byte $E1 ; previous-row copy count
    .byte $C3 ; same-value copy count/distance
    .byte $E6 ; previous-row copy count
    .byte $C4 ; same-value copy count/distance
