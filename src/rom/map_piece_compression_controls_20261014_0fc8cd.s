.setcpu "65816"
.segment "CODE"
.org $C8CD
map_control_0fc8cd:
    .byte $C4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
