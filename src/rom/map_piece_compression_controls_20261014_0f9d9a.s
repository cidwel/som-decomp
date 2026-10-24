.setcpu "65816"
.segment "CODE"
.org $9D9A
map_control_0f9d9a:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
