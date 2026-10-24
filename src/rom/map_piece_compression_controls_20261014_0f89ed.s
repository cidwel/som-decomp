.setcpu "65816"
.segment "CODE"
.org $89ED
map_control_0f89ed:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
