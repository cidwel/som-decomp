.setcpu "65816"
.segment "CODE"
.org $F711
map_control_0df711:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
