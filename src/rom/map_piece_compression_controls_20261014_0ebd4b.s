.setcpu "65816"
.segment "CODE"
.org $BD4B
map_control_0ebd4b:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
