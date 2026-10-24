.setcpu "65816"
.segment "CODE"
.org $658A
map_control_0d658a:
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
