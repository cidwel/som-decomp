.setcpu "65816"
.segment "CODE"
.org $C670
map_control_0fc670:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
