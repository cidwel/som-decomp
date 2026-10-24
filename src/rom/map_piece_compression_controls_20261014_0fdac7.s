.setcpu "65816"
.segment "CODE"
.org $DAC7
map_control_0fdac7:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
