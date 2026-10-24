.setcpu "65816"
.segment "CODE"
.org $7017
map_control_0d7017:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
