.setcpu "65816"
.segment "CODE"
.org $691D
map_control_0e691d:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
