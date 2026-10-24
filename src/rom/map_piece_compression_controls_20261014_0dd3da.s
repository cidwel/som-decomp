.setcpu "65816"
.segment "CODE"
.org $D3DA
map_control_0dd3da:
    .byte $E0 ; previous-row copy escape
    .byte $29 ; row-distance/count
