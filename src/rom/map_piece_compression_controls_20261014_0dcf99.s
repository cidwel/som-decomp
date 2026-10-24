.setcpu "65816"
.segment "CODE"
.org $CF99
map_control_0dcf99:
    .byte $E0 ; previous-row copy escape
    .byte $3A ; row-distance/count
