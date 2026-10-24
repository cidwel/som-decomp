.setcpu "65816"
.segment "CODE"
.org $981C
map_control_0d981c:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
