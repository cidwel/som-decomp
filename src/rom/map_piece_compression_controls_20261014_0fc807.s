.setcpu "65816"
.segment "CODE"
.org $C807
map_control_0fc807:
    .byte $E0 ; previous-row copy escape
    .byte $2A ; row-distance/count
