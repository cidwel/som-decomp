.setcpu "65816"
.segment "CODE"
.org $6A82
map_control_0d6a82:
    .byte $C2 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
    .byte $D6 ; same-value copy count/distance
