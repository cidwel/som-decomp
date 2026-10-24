.setcpu "65816"
.segment "CODE"
.org $7AB8
map_control_0f7ab8:
    .byte $C6 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
