.setcpu "65816"
.segment "CODE"
.org $1C9E
map_control_0d1c9e:
    .byte $E0 ; previous-row copy escape
    .byte $87 ; row-distance/count
