.setcpu "65816"
.segment "CODE"
.org $BA0F
map_control_0fba0f:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
