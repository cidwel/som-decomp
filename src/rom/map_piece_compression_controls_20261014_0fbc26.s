.setcpu "65816"
.segment "CODE"
.org $BC26
map_control_0fbc26:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
