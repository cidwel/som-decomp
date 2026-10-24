.setcpu "65816"
.segment "CODE"
.org $D5DD
map_control_0dd5dd:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
