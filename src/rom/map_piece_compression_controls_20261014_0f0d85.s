.setcpu "65816"
.segment "CODE"
.org $0D85
map_control_0f0d85:
    .byte $C4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
