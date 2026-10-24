.setcpu "65816"
.segment "CODE"
.org $C3FF
map_control_0fc3ff:
    .byte $E0 ; previous-row copy escape
    .byte $25 ; row-distance/count
