.setcpu "65816"
.segment "CODE"
.org $4395
map_control_0c4395:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
