.setcpu "65816"
.segment "CODE"
.org $71FB
map_control_0f71fb:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
