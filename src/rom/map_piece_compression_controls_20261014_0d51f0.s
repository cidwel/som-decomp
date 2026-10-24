.setcpu "65816"
.segment "CODE"
.org $51F0
map_control_0d51f0:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
