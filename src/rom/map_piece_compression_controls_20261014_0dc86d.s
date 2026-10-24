.setcpu "65816"
.segment "CODE"
.org $C86D
map_control_0dc86d:
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
