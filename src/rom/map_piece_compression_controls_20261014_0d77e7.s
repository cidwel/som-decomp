.setcpu "65816"
.segment "CODE"
.org $77E7
map_control_0d77e7:
    .byte $C4 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
