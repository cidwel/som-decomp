.setcpu "65816"
.segment "CODE"
.org $C6A6
map_control_0fc6a6:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
