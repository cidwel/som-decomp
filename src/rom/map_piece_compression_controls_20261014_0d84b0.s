.setcpu "65816"
.segment "CODE"
.org $84B0
map_control_0d84b0:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
