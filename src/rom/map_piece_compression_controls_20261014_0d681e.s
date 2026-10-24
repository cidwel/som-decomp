.setcpu "65816"
.segment "CODE"
.org $681E
map_control_0d681e:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
