.setcpu "65816"
.segment "CODE"
.org $D3E1
map_control_0dd3e1:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $20 ; row-distance/count
