.setcpu "65816"
.segment "CODE"
.org $1A89
map_control_0c1a89:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
