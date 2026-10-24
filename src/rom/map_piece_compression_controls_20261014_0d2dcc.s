.setcpu "65816"
.segment "CODE"
.org $2DCC
map_control_0d2dcc:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
