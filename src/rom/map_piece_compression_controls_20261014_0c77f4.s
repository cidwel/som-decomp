.setcpu "65816"
.segment "CODE"
.org $77F4
map_control_0c77f4:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
