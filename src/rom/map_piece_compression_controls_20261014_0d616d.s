.setcpu "65816"
.segment "CODE"
.org $616D
map_control_0d616d:
    .byte $D1 ; same-value copy count/distance
    .byte $E6 ; previous-row copy count
