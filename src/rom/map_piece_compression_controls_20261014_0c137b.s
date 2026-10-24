.setcpu "65816"
.segment "CODE"
.org $137B
map_control_0c137b:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
