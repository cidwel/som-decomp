.setcpu "65816"
.segment "CODE"
.org $9E6E
map_control_0f9e6e:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
