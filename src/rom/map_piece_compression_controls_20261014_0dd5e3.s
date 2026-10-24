.setcpu "65816"
.segment "CODE"
.org $D5E3
map_control_0dd5e3:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
