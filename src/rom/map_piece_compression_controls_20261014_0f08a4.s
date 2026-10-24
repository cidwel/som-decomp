.setcpu "65816"
.segment "CODE"
.org $08A4
map_control_0f08a4:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
