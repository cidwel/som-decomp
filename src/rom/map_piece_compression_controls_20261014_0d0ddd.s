.setcpu "65816"
.segment "CODE"
.org $0DDD
map_control_0d0ddd:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
