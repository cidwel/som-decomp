.setcpu "65816"
.segment "CODE"
.org $7DA1
map_control_0e7da1:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
