.setcpu "65816"
.segment "CODE"
.org $B86D
map_control_0db86d:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
