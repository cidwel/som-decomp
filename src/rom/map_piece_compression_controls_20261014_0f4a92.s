.setcpu "65816"
.segment "CODE"
.org $4A92
map_control_0f4a92:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
