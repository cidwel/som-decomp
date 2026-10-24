.setcpu "65816"
.segment "CODE"
.org $0210
map_control_0f0210:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
