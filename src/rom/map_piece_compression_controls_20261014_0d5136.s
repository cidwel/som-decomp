.setcpu "65816"
.segment "CODE"
.org $5136
map_control_0d5136:
    .byte $CC ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
