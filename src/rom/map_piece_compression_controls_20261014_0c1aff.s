.setcpu "65816"
.segment "CODE"
.org $1AFF
map_control_0c1aff:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
