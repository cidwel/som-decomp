.setcpu "65816"
.segment "CODE"
.org $C911
map_control_0fc911:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
    .byte $C3 ; same-value copy count/distance
