.setcpu "65816"
.segment "CODE"
.org $C937
map_control_0fc937:
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count
    .byte $C6 ; same-value copy count/distance
