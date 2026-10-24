.setcpu "65816"
.segment "CODE"
.org $DC3C
map_control_0ddc3c:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
