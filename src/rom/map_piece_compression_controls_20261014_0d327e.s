.setcpu "65816"
.segment "CODE"
.org $327E
map_control_0d327e:
    .byte $E0 ; previous-row copy escape
    .byte $91 ; row-distance/count
