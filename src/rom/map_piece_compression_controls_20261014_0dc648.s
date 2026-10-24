.setcpu "65816"
.segment "CODE"
.org $C648
map_control_0dc648:
    .byte $E4 ; previous-row copy count
    .byte $C5 ; same-value copy count/distance
