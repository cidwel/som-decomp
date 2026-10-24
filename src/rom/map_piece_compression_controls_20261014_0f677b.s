.setcpu "65816"
.segment "CODE"
.org $677B
map_control_0f677b:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
