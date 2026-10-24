.setcpu "65816"
.segment "CODE"
.org $286A
map_control_0e286a:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
