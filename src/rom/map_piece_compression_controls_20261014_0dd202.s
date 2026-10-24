.setcpu "65816"
.segment "CODE"
.org $D202
map_control_0dd202:
    .byte $E4 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
    .byte $D2 ; same-value copy count/distance
