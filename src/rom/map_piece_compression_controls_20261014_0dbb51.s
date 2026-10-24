.setcpu "65816"
.segment "CODE"
.org $BB51
map_control_0dbb51:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
