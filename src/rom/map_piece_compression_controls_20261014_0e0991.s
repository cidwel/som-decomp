.setcpu "65816"
.segment "CODE"
.org $0991
map_control_0e0991:
    .byte $E0 ; previous-row copy escape
    .byte $8A ; row-distance/count
    .byte $C2 ; same-value copy count/distance
