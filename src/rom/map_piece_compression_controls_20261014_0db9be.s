.setcpu "65816"
.segment "CODE"
.org $B9BE
map_control_0db9be:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
