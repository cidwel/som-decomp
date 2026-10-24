.setcpu "65816"
.segment "CODE"
.org $C558
map_control_0fc558:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
