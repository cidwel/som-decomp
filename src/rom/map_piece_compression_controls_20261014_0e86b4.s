.setcpu "65816"
.segment "CODE"
.org $86B4
map_control_0e86b4:
    .byte $C5 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
