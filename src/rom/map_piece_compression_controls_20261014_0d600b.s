.setcpu "65816"
.segment "CODE"
.org $600B
map_control_0d600b:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
