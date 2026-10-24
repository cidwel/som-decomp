.setcpu "65816"
.segment "CODE"
.org $196A
map_control_0f196a:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
