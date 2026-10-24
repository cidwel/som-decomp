.setcpu "65816"
.segment "CODE"
.org $8DCA
map_control_0f8dca:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
