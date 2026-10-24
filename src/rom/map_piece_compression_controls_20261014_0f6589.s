.setcpu "65816"
.segment "CODE"
.org $6589
map_control_0f6589:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
