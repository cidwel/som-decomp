.setcpu "65816"
.segment "CODE"
.org $2FD4
map_control_0f2fd4:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
