.setcpu "65816"
.segment "CODE"
.org $2DE4
map_control_0f2de4:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
