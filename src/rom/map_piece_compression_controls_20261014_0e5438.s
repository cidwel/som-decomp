.setcpu "65816"
.segment "CODE"
.org $5438
map_control_0e5438:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
