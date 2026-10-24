.setcpu "65816"
.segment "CODE"
.org $80A9
map_control_0e80a9:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
