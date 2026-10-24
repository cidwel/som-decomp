.setcpu "65816"
.segment "CODE"
.org $BC3C
map_control_0fbc3c:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
