.setcpu "65816"
.segment "CODE"
.org $C972
map_control_0fc972:
    .byte $C3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
