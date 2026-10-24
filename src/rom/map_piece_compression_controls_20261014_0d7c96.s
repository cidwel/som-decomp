.setcpu "65816"
.segment "CODE"
.org $7C96
map_control_0d7c96:
    .byte $DA ; same-value copy count/distance
    .byte $E7 ; previous-row copy count
