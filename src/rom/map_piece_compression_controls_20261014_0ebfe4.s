.setcpu "65816"
.segment "CODE"
.org $BFE4
map_control_0ebfe4:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
