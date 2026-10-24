.setcpu "65816"
.segment "CODE"
.org $E95E
map_control_0ee95e:
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
