.setcpu "65816"
.segment "CODE"
.org $BFF0
map_control_0fbff0:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
