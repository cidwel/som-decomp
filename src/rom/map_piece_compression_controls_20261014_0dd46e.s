.setcpu "65816"
.segment "CODE"
.org $D46E
map_control_0dd46e:
    .byte $E0 ; previous-row copy escape
    .byte $99 ; row-distance/count
