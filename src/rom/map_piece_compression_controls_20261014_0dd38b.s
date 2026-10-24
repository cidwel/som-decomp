.setcpu "65816"
.segment "CODE"
.org $D38B
map_control_0dd38b:
    .byte $E2 ; previous-row copy count
    .byte $C3 ; same-value copy count/distance
