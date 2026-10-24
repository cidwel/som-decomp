.setcpu "65816"
.segment "CODE"
.org $757B
map_control_0f757b:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
