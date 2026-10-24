.setcpu "65816"
.segment "CODE"
.org $C545
map_control_0fc545:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
