.setcpu "65816"
.segment "CODE"
.org $C8B4
map_control_0ec8b4:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
