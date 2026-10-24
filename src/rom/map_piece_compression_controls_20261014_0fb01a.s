.setcpu "65816"
.segment "CODE"
.org $B01A
map_control_0fb01a:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
