.setcpu "65816"
.segment "CODE"
.org $AFC7
map_control_0eafc7:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
