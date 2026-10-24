.setcpu "65816"
.segment "CODE"
.org $744A
map_control_0e744a:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
