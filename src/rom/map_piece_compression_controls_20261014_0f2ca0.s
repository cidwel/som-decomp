.setcpu "65816"
.segment "CODE"
.org $2CA0
map_control_0f2ca0:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
