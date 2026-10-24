.setcpu "65816"
.segment "CODE"
.org $9A41
map_control_0f9a41:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
