.setcpu "65816"
.segment "CODE"
.org $E0B0
map_control_0de0b0:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
