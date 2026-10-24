.setcpu "65816"
.segment "CODE"
.org $0DCA
map_control_0f0dca:
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
