.setcpu "65816"
.segment "CODE"
.org $DE3A
map_control_0ede3a:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
