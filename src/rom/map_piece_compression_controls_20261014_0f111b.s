.setcpu "65816"
.segment "CODE"
.org $111B
map_control_0f111b:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
