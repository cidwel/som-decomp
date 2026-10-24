.setcpu "65816"
.segment "CODE"
.org $8EDF
map_control_0e8edf:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
