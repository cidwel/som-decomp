.setcpu "65816"
.segment "CODE"
.org $8CEC
map_control_0f8cec:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
