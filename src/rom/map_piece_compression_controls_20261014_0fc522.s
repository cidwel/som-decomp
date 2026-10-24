.setcpu "65816"
.segment "CODE"
.org $C522
map_control_0fc522:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
