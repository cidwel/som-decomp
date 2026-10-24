.setcpu "65816"
.segment "CODE"
.org $452D
map_control_0c452d:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
