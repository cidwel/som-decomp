.setcpu "65816"
.segment "CODE"
.org $0F3A
map_control_0f0f3a:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
