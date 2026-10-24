.setcpu "65816"
.segment "CODE"
.org $3B99
map_control_0f3b99:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
