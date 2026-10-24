.setcpu "65816"
.segment "CODE"
.org $0054
map_control_0f0054:
    .byte $E0 ; previous-row copy escape
    .byte $8A ; row-distance/count
