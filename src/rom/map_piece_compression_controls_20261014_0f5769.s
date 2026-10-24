.setcpu "65816"
.segment "CODE"
.org $5769
map_control_0f5769:
    .byte $D1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
