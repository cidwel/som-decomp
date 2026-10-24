.setcpu "65816"
.segment "CODE"
.org $ED8D
map_control_0eed8d:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
