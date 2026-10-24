.setcpu "65816"
.segment "CODE"
.org $652B
map_control_0f652b:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
