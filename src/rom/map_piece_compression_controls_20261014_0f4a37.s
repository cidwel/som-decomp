.setcpu "65816"
.segment "CODE"
.org $4A37
map_control_0f4a37:
    .byte $E0 ; previous-row copy escape
    .byte $3F ; row-distance/count
