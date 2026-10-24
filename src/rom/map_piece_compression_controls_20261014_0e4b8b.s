.setcpu "65816"
.segment "CODE"
.org $4B8B
map_control_0e4b8b:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
