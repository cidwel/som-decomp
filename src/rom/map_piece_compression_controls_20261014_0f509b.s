.setcpu "65816"
.segment "CODE"
.org $509B
map_control_0f509b:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
