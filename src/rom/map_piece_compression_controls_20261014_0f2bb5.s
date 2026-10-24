.setcpu "65816"
.segment "CODE"
.org $2BB5
map_control_0f2bb5:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
