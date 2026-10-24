.setcpu "65816"
.segment "CODE"
.org $B337
map_control_0db337:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
