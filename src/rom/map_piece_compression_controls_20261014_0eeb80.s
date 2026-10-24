.setcpu "65816"
.segment "CODE"
.org $EB80
map_control_0eeb80:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
