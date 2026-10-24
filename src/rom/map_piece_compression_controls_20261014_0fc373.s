.setcpu "65816"
.segment "CODE"
.org $C373
map_control_0fc373:
    .byte $E0 ; previous-row copy escape
    .byte $3B ; row-distance/count
