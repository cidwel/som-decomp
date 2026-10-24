.setcpu "65816"
.segment "CODE"
.org $9E9E
map_control_0f9e9e:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
