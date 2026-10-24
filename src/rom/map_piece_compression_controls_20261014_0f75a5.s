.setcpu "65816"
.segment "CODE"
.org $75A5
map_control_0f75a5:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
