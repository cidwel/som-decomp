.setcpu "65816"
.segment "CODE"
.org $69F6
map_control_0e69f6:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
