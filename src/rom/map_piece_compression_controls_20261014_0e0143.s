.setcpu "65816"
.segment "CODE"
.org $0143
map_control_0e0143:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
