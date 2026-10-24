.setcpu "65816"
.segment "CODE"
.org $B618
map_control_0eb618:
    .byte $E0 ; previous-row copy escape
    .byte $95 ; row-distance/count
