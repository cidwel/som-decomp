.setcpu "65816"
.segment "CODE"
.org $B1C5
map_control_0fb1c5:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
