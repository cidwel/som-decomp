.setcpu "65816"
.segment "CODE"
.org $FB8B
map_control_0dfb8b:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
    .byte $C5 ; same-value copy count/distance
