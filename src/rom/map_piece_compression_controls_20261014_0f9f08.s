.setcpu "65816"
.segment "CODE"
.org $9F08
map_control_0f9f08:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
