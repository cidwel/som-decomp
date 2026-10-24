.setcpu "65816"
.segment "CODE"
.org $0DE4
map_control_0c0de4:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
