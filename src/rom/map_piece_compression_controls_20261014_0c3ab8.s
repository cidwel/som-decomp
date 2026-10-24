.setcpu "65816"
.segment "CODE"
.org $3AB8
map_control_0c3ab8:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
