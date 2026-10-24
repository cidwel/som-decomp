.setcpu "65816"
.segment "CODE"
.org $E054
map_control_0fe054:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
