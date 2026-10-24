.setcpu "65816"
.segment "CODE"
.org $C3B5
map_control_0fc3b5:
    .byte $D6 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
