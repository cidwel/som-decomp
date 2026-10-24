.setcpu "65816"
.segment "CODE"
.org $66BE
map_control_0f66be:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
