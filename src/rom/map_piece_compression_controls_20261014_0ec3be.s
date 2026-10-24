.setcpu "65816"
.segment "CODE"
.org $C3BE
map_control_0ec3be:
    .byte $E1 ; previous-row copy count
    .byte $D1 ; same-value copy count/distance
