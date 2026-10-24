.setcpu "65816"
.segment "CODE"
.org $8B76
map_control_0d8b76:
    .byte $C1 ; same-value copy count/distance
    .byte $D9 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
