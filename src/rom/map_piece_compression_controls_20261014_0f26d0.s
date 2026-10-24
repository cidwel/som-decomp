.setcpu "65816"
.segment "CODE"
.org $26D0
map_control_0f26d0:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
