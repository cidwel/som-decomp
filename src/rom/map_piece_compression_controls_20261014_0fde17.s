.setcpu "65816"
.segment "CODE"
.org $DE17
map_control_0fde17:
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
