.setcpu "65816"
.segment "CODE"
.org $D118
map_control_0ed118:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
