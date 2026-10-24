.setcpu "65816"
.segment "CODE"
.org $151D
map_control_0c151d:
    .byte $E0 ; previous-row copy escape
    .byte $20 ; row-distance/count
