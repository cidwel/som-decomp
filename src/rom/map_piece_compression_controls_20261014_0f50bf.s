.setcpu "65816"
.segment "CODE"
.org $50BF
map_control_0f50bf:
    .byte $E0 ; previous-row copy escape
    .byte $84 ; row-distance/count
    .byte $C3 ; same-value copy count/distance
