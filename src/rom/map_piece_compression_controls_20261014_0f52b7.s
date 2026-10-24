.setcpu "65816"
.segment "CODE"
.org $52B7
map_control_0f52b7:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
