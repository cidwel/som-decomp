.setcpu "65816"
.segment "CODE"
.org $D27A
map_control_0dd27a:
    .byte $C6 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
