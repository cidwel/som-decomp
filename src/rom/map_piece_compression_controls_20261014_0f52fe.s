.setcpu "65816"
.segment "CODE"
.org $52FE
map_control_0f52fe:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
