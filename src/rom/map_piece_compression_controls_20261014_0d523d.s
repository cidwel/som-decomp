.setcpu "65816"
.segment "CODE"
.org $523D
map_control_0d523d:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
