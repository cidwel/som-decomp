.setcpu "65816"
.segment "CODE"
.org $DD52
map_control_0edd52:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
