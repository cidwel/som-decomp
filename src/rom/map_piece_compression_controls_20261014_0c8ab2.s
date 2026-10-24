.setcpu "65816"
.segment "CODE"
.org $8AB2
map_control_0c8ab2:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
