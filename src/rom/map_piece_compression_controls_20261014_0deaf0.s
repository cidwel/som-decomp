.setcpu "65816"
.segment "CODE"
.org $EAF0
map_control_0deaf0:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
