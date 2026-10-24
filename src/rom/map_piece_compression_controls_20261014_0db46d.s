.setcpu "65816"
.segment "CODE"
.org $B46D
map_control_0db46d:
    .byte $E7 ; previous-row copy count
    .byte $C5 ; same-value copy count/distance
