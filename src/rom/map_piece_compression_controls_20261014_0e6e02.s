.setcpu "65816"
.segment "CODE"
.org $6E02
map_control_0e6e02:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
