.setcpu "65816"
.segment "CODE"
.org $C5E6
map_control_0fc5e6:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
    .byte $C2 ; same-value copy count/distance
