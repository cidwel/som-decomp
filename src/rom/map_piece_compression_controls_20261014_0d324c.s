.setcpu "65816"
.segment "CODE"
.org $324C
map_control_0d324c:
    .byte $E0 ; previous-row copy escape
    .byte $96 ; row-distance/count
