.setcpu "65816"
.segment "CODE"
.org $FA58
map_control_0dfa58:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
