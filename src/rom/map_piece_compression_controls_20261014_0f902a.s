.setcpu "65816"
.segment "CODE"
.org $902A
map_control_0f902a:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
