.setcpu "65816"
.segment "CODE"
.org $047B
map_control_0e047b:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
