.setcpu "65816"
.segment "CODE"
.org $D1B0
map_control_0fd1b0:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
