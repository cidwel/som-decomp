.setcpu "65816"
.segment "CODE"
.org $929A
map_control_0e929a:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
