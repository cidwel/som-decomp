.setcpu "65816"
.segment "CODE"
.org $6E91
map_control_0e6e91:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
