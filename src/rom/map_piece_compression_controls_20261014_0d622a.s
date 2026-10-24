.setcpu "65816"
.segment "CODE"
.org $622A
map_control_0d622a:
    .byte $E0 ; previous-row copy escape
    .byte $88 ; row-distance/count
