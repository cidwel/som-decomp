.setcpu "65816"
.segment "CODE"
.org $C619
map_control_0fc619:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
