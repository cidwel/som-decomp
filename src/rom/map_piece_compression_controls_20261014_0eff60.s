.setcpu "65816"
.segment "CODE"
.org $FF60
map_control_0eff60:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
