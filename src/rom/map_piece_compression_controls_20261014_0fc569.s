.setcpu "65816"
.segment "CODE"
.org $C569
map_control_0fc569:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
