.setcpu "65816"
.segment "CODE"
.org $5D55
map_control_0e5d55:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
