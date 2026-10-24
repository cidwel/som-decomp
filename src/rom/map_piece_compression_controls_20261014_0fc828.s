.setcpu "65816"
.segment "CODE"
.org $C828
map_control_0fc828:
    .byte $C6 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
