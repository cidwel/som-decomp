.setcpu "65816"
.segment "CODE"
.org $49A4
map_control_0f49a4:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
