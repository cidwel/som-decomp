.setcpu "65816"
.segment "CODE"
.org $D5C5
map_control_0dd5c5:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
