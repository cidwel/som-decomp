.setcpu "65816"
.segment "CODE"
.org $39B1
map_control_0f39b1:
    .byte $C4 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
