.setcpu "65816"
.segment "CODE"
.org $CB32
map_control_0fcb32:
    .byte $E0 ; previous-row copy escape
    .byte $24 ; row-distance/count
