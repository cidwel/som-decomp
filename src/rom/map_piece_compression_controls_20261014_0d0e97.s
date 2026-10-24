.setcpu "65816"
.segment "CODE"
.org $0E97
map_control_0d0e97:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
