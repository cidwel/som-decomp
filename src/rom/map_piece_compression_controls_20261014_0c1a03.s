.setcpu "65816"
.segment "CODE"
.org $1A03
map_control_0c1a03:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
