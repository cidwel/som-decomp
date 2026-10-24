.setcpu "65816"
.segment "CODE"
.org $0F3C
map_control_0e0f3c:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
