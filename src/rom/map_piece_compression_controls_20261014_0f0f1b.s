.setcpu "65816"
.segment "CODE"
.org $0F1B
map_control_0f0f1b:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
