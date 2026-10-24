.setcpu "65816"
.segment "CODE"
.org $3EFB
map_control_0f3efb:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
