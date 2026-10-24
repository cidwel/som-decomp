.setcpu "65816"
.segment "CODE"
.org $4DA5
map_control_0f4da5:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
