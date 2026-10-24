.setcpu "65816"
.segment "CODE"
.org $276B
map_control_0c276b:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
