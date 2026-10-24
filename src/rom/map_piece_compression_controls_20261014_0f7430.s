.setcpu "65816"
.segment "CODE"
.org $7430
map_control_0f7430:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
