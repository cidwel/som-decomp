.setcpu "65816"
.segment "CODE"
.org $3BD3
map_control_0f3bd3:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
