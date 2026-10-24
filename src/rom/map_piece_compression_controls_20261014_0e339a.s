.setcpu "65816"
.segment "CODE"
.org $339A
map_control_0e339a:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
