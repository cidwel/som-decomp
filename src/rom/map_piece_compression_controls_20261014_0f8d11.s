.setcpu "65816"
.segment "CODE"
.org $8D11
map_control_0f8d11:
    .byte $E0 ; previous-row copy escape
    .byte $34 ; row-distance/count
