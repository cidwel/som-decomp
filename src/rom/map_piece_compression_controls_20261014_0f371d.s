.setcpu "65816"
.segment "CODE"
.org $371D
map_control_0f371d:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
