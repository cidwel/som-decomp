.setcpu "65816"
.segment "CODE"
.org $CF58
map_control_0ecf58:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
