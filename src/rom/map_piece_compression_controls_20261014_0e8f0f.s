.setcpu "65816"
.segment "CODE"
.org $8F0F
map_control_0e8f0f:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
    .byte $C3 ; same-value copy count/distance
