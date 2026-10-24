.setcpu "65816"
.segment "CODE"
.org $CA59
map_control_0fca59:
    .byte $E0 ; previous-row copy escape
    .byte $87 ; row-distance/count
