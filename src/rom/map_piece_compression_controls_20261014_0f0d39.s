.setcpu "65816"
.segment "CODE"
.org $0D39
map_control_0f0d39:
    .byte $E0 ; previous-row copy escape
    .byte $23 ; row-distance/count
