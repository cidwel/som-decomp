.setcpu "65816"
.segment "CODE"
.org $90F0
map_control_0c90f0:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
