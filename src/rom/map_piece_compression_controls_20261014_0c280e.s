.setcpu "65816"
.segment "CODE"
.org $280E
map_control_0c280e:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
