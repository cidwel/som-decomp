.setcpu "65816"
.segment "CODE"
.org $C716
map_control_0fc716:
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
    .byte $C1 ; same-value copy count/distance
