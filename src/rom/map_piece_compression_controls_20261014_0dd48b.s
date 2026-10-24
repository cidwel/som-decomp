.setcpu "65816"
.segment "CODE"
.org $D48B
map_control_0dd48b:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
