.setcpu "65816"
.segment "CODE"
.org $6BDA
map_control_0e6bda:
    .byte $E0 ; previous-row copy escape
    .byte $23 ; row-distance/count
    .byte $C3 ; same-value copy count/distance
