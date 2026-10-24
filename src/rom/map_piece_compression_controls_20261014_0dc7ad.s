.setcpu "65816"
.segment "CODE"
.org $C7AD
map_control_0dc7ad:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
