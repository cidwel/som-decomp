.setcpu "65816"
.segment "CODE"
.org $C826
map_control_0dc826:
    .byte $E0 ; previous-row copy escape
    .byte $24 ; row-distance/count
