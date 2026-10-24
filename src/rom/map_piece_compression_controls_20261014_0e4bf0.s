.setcpu "65816"
.segment "CODE"
.org $4BF0
map_control_0e4bf0:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
