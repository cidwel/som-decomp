.setcpu "65816"
.segment "CODE"
.org $4D49
map_control_0f4d49:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
