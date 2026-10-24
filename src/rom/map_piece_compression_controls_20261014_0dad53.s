.setcpu "65816"
.segment "CODE"
.org $AD53
map_control_0dad53:
    .byte $E0 ; previous-row copy escape
    .byte $44 ; row-distance/count
