.setcpu "65816"
.segment "CODE"
.org $124C
map_control_0e124c:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
