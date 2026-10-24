.setcpu "65816"
.segment "CODE"
.org $C573
map_control_0fc573:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
