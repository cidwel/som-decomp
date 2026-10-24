.setcpu "65816"
.segment "CODE"
.org $7A01
map_control_0d7a01:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
