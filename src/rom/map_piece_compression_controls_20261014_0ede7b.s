.setcpu "65816"
.segment "CODE"
.org $DE7B
map_control_0ede7b:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
