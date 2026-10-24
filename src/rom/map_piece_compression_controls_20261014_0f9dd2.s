.setcpu "65816"
.segment "CODE"
.org $9DD2
map_control_0f9dd2:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
