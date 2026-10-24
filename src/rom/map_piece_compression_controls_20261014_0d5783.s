.setcpu "65816"
.segment "CODE"
.org $5783
map_control_0d5783:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
    .byte $DA ; same-value copy count/distance
