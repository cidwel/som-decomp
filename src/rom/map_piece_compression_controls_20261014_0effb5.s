.setcpu "65816"
.segment "CODE"
.org $FFB5
map_control_0effb5:
    .byte $E0 ; previous-row copy escape
    .byte $8B ; row-distance/count
