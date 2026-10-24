.setcpu "65816"
.segment "CODE"
.org $E633
map_control_0fe633:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
