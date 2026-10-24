.setcpu "65816"
.segment "CODE"
.org $50F6
map_control_0f50f6:
    .byte $D3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
