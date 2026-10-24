.setcpu "65816"
.segment "CODE"
.org $0BA9
map_control_0d0ba9:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
