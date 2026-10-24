.setcpu "65816"
.segment "CODE"
.org $5491
map_control_0d5491:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
