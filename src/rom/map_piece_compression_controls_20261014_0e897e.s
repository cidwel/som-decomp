.setcpu "65816"
.segment "CODE"
.org $897E
map_control_0e897e:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
