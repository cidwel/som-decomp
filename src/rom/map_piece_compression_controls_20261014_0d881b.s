.setcpu "65816"
.segment "CODE"
.org $881B
map_control_0d881b:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
