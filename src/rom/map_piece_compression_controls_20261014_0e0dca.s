.setcpu "65816"
.segment "CODE"
.org $0DCA
map_control_0e0dca:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
