.setcpu "65816"
.segment "CODE"
.org $F868
map_control_0ff868:
    .byte $E0 ; previous-row copy escape
    .byte $27 ; row-distance/count
