.setcpu "65816"
.segment "CODE"
.org $6B16
map_control_0f6b16:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
