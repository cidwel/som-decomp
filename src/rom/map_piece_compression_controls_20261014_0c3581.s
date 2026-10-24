.setcpu "65816"
.segment "CODE"
.org $3581
map_control_0c3581:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
