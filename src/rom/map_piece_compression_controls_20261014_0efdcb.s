.setcpu "65816"
.segment "CODE"
.org $FDCB
map_control_0efdcb:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
