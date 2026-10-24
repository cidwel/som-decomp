.setcpu "65816"
.segment "CODE"
.org $C8A5
map_control_0fc8a5:
    .byte $C4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
