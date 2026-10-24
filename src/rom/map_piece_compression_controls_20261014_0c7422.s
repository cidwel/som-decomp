.setcpu "65816"
.segment "CODE"
.org $7422
map_control_0c7422:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
