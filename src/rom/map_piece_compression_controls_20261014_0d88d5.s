.setcpu "65816"
.segment "CODE"
.org $88D5
map_control_0d88d5:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
