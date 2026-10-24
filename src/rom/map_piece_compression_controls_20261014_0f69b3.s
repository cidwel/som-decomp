.setcpu "65816"
.segment "CODE"
.org $69B3
map_control_0f69b3:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
