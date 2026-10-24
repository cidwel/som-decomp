.setcpu "65816"
.segment "CODE"
.org $C346
map_control_0fc346:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
