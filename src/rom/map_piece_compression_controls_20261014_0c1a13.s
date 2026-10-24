.setcpu "65816"
.segment "CODE"
.org $1A13
map_control_0c1a13:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
