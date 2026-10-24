.setcpu "65816"
.segment "CODE"
.org $F4F6
map_control_0df4f6:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
