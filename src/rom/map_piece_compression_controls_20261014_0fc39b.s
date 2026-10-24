.setcpu "65816"
.segment "CODE"
.org $C39B
map_control_0fc39b:
    .byte $E0 ; previous-row copy escape
    .byte $9B ; row-distance/count
