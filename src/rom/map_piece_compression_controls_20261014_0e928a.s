.setcpu "65816"
.segment "CODE"
.org $928A
map_control_0e928a:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
