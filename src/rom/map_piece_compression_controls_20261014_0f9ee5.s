.setcpu "65816"
.segment "CODE"
.org $9EE5
map_control_0f9ee5:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
