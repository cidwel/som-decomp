.setcpu "65816"
.segment "CODE"
.org $0225
map_control_0f0225:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
