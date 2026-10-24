.setcpu "65816"
.segment "CODE"
.org $4DD1
map_control_0e4dd1:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
