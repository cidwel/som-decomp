.setcpu "65816"
.segment "CODE"
.org $BD40
map_control_0dbd40:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
