.setcpu "65816"
.segment "CODE"
.org $305F
map_control_0c305f:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
    .byte $C1 ; same-value copy count/distance
