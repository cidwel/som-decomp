.setcpu "65816"
.segment "CODE"
.org $C5AF
map_control_0fc5af:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
