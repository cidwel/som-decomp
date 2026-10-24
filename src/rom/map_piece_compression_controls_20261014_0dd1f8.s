.setcpu "65816"
.segment "CODE"
.org $D1F8
map_control_0dd1f8:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
