.setcpu "65816"
.segment "CODE"
.org $888B
map_control_0d888b:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
