.setcpu "65816"
.segment "CODE"
.org $9E9E
map_control_0d9e9e:
    .byte $E0 ; previous-row copy escape
    .byte $3F ; row-distance/count
