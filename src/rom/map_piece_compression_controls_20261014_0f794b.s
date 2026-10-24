.setcpu "65816"
.segment "CODE"
.org $794B
map_control_0f794b:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
