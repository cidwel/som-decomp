.setcpu "65816"
.segment "CODE"
.org $C4B4
map_control_0fc4b4:
    .byte $E0 ; previous-row copy escape
    .byte $24 ; row-distance/count
