.setcpu "65816"
.segment "CODE"
.org $FC55
map_control_0ffc55:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
