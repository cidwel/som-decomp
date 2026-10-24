.setcpu "65816"
.segment "CODE"
.org $C6F0
map_control_0fc6f0:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
