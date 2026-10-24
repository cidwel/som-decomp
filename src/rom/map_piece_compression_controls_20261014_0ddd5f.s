.setcpu "65816"
.segment "CODE"
.org $DD5F
map_control_0ddd5f:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
