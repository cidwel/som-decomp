.setcpu "65816"
.segment "CODE"
.org $742A
map_control_0e742a:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
