.setcpu "65816"
.segment "CODE"
.org $747B
map_control_0f747b:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
