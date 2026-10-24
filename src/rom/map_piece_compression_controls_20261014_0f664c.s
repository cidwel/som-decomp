.setcpu "65816"
.segment "CODE"
.org $664C
map_control_0f664c:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
