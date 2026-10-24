.setcpu "65816"
.segment "CODE"
.org $57B3
map_control_0d57b3:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
