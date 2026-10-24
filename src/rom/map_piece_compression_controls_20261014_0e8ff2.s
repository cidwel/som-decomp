.setcpu "65816"
.segment "CODE"
.org $8FF2
map_control_0e8ff2:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
