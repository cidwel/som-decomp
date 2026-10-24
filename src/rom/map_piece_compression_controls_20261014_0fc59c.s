.setcpu "65816"
.segment "CODE"
.org $C59C
map_control_0fc59c:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
