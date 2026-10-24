.setcpu "65816"
.segment "CODE"
.org $5C25
map_control_0f5c25:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
