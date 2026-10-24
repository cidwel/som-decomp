.setcpu "65816"
.segment "CODE"
.org $C90A
map_control_0fc90a:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
