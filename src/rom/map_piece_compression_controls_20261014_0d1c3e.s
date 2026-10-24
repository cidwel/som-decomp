.setcpu "65816"
.segment "CODE"
.org $1C3E
map_control_0d1c3e:
    .byte $E0 ; previous-row copy escape
    .byte $25 ; row-distance/count
