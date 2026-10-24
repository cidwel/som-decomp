.setcpu "65816"
.segment "CODE"
.org $60F1
map_control_0e60f1:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
