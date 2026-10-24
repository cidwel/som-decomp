.setcpu "65816"
.segment "CODE"
.org $CEE0
map_control_0ecee0:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
