.setcpu "65816"
.segment "CODE"
.org $4EF6
map_control_0f4ef6:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
