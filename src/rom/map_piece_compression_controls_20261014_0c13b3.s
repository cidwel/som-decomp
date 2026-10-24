.setcpu "65816"
.segment "CODE"
.org $13B3
map_control_0c13b3:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
