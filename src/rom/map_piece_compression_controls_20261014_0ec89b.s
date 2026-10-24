.setcpu "65816"
.segment "CODE"
.org $C89B
map_control_0ec89b:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
