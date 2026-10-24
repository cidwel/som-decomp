.setcpu "65816"
.segment "CODE"
.org $25E3
map_control_0d25e3:
    .byte $C5 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
