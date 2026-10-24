.setcpu "65816"
.segment "CODE"
.org $86F8
map_control_0f86f8:
    .byte $E1 ; previous-row copy count
    .byte $D1 ; same-value copy count/distance
