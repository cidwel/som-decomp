.setcpu "65816"
.segment "CODE"
.org $845E
map_control_0d845e:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
