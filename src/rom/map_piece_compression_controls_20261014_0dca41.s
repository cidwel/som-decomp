.setcpu "65816"
.segment "CODE"
.org $CA41
map_control_0dca41:
    .byte $E0 ; previous-row copy escape
    .byte $20 ; row-distance/count
