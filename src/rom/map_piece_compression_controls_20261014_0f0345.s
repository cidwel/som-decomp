.setcpu "65816"
.segment "CODE"
.org $0345
map_control_0f0345:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
