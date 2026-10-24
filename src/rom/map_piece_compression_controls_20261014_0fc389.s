.setcpu "65816"
.segment "CODE"
.org $C389
map_control_0fc389:
    .byte $E0 ; previous-row copy escape
    .byte $AE ; row-distance/count
