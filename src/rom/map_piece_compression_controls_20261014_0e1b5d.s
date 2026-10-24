.setcpu "65816"
.segment "CODE"
.org $1B5D
map_control_0e1b5d:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
