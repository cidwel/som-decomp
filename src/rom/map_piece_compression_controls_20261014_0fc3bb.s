.setcpu "65816"
.segment "CODE"
.org $C3BB
map_control_0fc3bb:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
