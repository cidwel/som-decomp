.setcpu "65816"
.segment "CODE"
.org $6BD8
map_control_0c6bd8:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
