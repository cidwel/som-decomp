.setcpu "65816"
.segment "CODE"
.org $C929
map_control_0ec929:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
