.setcpu "65816"
.segment "CODE"
.org $C5C4
map_control_0fc5c4:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
