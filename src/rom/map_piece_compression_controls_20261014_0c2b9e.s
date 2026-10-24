.setcpu "65816"
.segment "CODE"
.org $2B9E
map_control_0c2b9e:
    .byte $E0 ; previous-row copy escape
    .byte $25 ; row-distance/count
