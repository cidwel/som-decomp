.setcpu "65816"
.segment "CODE"
.org $7EDF
map_control_0e7edf:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
