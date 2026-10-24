.setcpu "65816"
.segment "CODE"
.org $2150
map_control_0d2150:
    .byte $E0 ; previous-row copy escape
    .byte $84 ; row-distance/count
