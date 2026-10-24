.setcpu "65816"
.segment "CODE"
.org $64B7
map_control_0e64b7:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
