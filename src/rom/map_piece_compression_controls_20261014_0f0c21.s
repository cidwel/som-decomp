.setcpu "65816"
.segment "CODE"
.org $0C21
map_control_0f0c21:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
