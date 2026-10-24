.setcpu "65816"
.segment "CODE"
.org $537E
map_control_0d537e:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
