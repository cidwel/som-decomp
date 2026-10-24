.setcpu "65816"
.segment "CODE"
.org $4C09
map_control_0f4c09:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
