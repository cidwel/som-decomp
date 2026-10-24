.setcpu "65816"
.segment "CODE"
.org $DB17
map_control_0edb17:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
