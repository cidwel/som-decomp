.setcpu "65816"
.segment "CODE"
.org $101A
map_control_0f101a:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
