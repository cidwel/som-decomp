.setcpu "65816"
.segment "CODE"
.org $F18A
map_control_0cf18a:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
