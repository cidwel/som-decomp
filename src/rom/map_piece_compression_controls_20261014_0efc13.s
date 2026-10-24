.setcpu "65816"
.segment "CODE"
.org $FC13
map_control_0efc13:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
