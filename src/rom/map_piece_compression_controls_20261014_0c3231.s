.setcpu "65816"
.segment "CODE"
.org $3231
map_control_0c3231:
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
