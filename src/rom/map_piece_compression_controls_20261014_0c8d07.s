.setcpu "65816"
.segment "CODE"
.org $8D07
map_control_0c8d07:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
