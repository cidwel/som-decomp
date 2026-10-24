.setcpu "65816"
.segment "CODE"
.org $4D34
map_control_0f4d34:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
