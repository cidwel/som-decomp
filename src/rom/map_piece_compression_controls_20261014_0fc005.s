.setcpu "65816"
.segment "CODE"
.org $C005
map_control_0fc005:
    .byte $C5 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
