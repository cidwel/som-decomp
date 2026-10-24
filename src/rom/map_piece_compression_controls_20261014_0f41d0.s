.setcpu "65816"
.segment "CODE"
.org $41D0
map_control_0f41d0:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
    .byte $DA ; same-value copy count/distance
    .byte $E7 ; previous-row copy count
