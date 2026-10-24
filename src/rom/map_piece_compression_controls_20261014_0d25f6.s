.setcpu "65816"
.segment "CODE"
.org $25F6
map_control_0d25f6:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
