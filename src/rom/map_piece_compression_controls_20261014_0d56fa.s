.setcpu "65816"
.segment "CODE"
.org $56FA
map_control_0d56fa:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
