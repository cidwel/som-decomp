.setcpu "65816"
.segment "CODE"
.org $2DFB
map_control_0f2dfb:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
