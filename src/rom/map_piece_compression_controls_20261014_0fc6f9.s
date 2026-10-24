.setcpu "65816"
.segment "CODE"
.org $C6F9
map_control_0fc6f9:
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
