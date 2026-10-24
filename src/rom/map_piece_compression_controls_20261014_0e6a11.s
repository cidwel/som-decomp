.setcpu "65816"
.segment "CODE"
.org $6A11
map_control_0e6a11:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
