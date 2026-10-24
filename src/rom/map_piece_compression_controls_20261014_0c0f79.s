.setcpu "65816"
.segment "CODE"
.org $0F79
map_control_0c0f79:
    .byte $E0 ; previous-row copy escape
    .byte $2A ; row-distance/count
