.setcpu "65816"
.segment "CODE"
.org $79B0
map_control_0d79b0:
    .byte $D3 ; same-value copy count/distance
    .byte $E7 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $A0 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
