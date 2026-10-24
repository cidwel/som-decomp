.setcpu "65816"
.segment "CODE"
.org $3193
map_control_0e3193:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
