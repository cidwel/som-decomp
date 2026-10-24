.setcpu "65816"
.segment "CODE"
.org $786A
map_control_0f786a:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
