.setcpu "65816"
.segment "CODE"
.org $7136
map_control_0d7136:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
