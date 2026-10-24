.setcpu "65816"
.segment "CODE"
.org $C0DA
map_control_0dc0da:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
