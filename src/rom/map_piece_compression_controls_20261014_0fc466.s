.setcpu "65816"
.segment "CODE"
.org $C466
map_control_0fc466:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
    .byte $C6 ; same-value copy count/distance
